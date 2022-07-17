import argparse
import requests
import random
import string
import json
import glob
import os.path
from pathlib import Path
from bs4 import BeautifulSoup
from getpass import *
from tps_parser import DataVisitor, get_data_mapping
from getpass import getpass

parser = argparse.ArgumentParser()
parser.add_argument("code", help="Your problem code")
parser.add_argument("-n", "--new", help="Add a new problem and print the problem id. (the problem id inside the script will be replaced, hence -i will be ignored)", action="store_true")
parser.add_argument("-i", "--id", help="Your corresponding problem ID, needed when you are not adding a new problem.", type=str, default="-1")
parser.add_argument("-a", "--all", help="Add the whole content of the problem. If -d, -t, -s, -j or -p is specified, then the script will skip the corresponding operation instead.", action="store_true")
parser.add_argument("-d", "--description", help="Upload problem description (those inside statement, samples (public/examples for interactive problem)).", action="store_true")
parser.add_argument("-t", "--testcases", help="Upload problem testcases.", action="store_true")
parser.add_argument("-u", "--update", help="If -u is specified, -t will be ignored, and those testcases have already existed on the judge will only update their metadata. Other non-existed testcases will be treated as new testcases and uploaded.\nA variable UPDATE should follow -u, the script will update the input file if UPDATE contains bit 0; the script will update the output file if UPDATE contains bit 1.\nThus using 0 can update only metadata.", type=int, default=-1)
parser.add_argument("-s", "--subtasks", help="Upload subtasks ranges.", action="store_true")
parser.add_argument("-j", "--judge", help="Upload judging related files (checker or header).", action="store_true")
parser.add_argument("-p", "--public", help="Upload public file links (those inside public/file.json).", action="store_true")
parser.add_argument("-g", "--group", help="Specify the group.", type=str, default='')
parser.add_argument("--user", help="Automatic login with a file USER. The file should contain only two lines, first line is the username and the second one is the password.", type=str, default="")
parser.add_argument("--nogen", help="Skip tps gen.", action="store_true")
parser.add_argument("--nocover", help="Do not cover the problem id.", action="store_true")
parser.add_argument("--nosample", help="Skip sample when uploading description.", action="store_true")
parser.add_argument("--makepublic", help="Make the problem public.", action="store_true")
parser.add_argument("--nostate", help="Not to change the problem state.", action="store_true")

args = parser.parse_args()

if not os.path.isdir(args.code):
    print('Fail! Cannot find %s' % args.code)
    exit(1)

if not args.nogen:
    if not os.path.isdir(args.code + '/tests'):
        print('Fail! You should always run tps gen first!')
        exit(1)

judge_url = 'https://tioj.ck.tp.edu.tw/'
# judge_url = 'http://linux8.csie.org:8192/'

session = requests.Session()

def login():
    if args.user != "" and os.path.isfile(args.user):
        userfile = Path(args.user).read_text().split('\n')
        TIOJusername = userfile[0]
        TIOJpassword = userfile[1]
    else:
        TIOJusername = input('Username: ')
        TIOJpassword = getpass()
    print('logging in...')
    global session
    rel = session.get(judge_url + 'users/sign_in')
    soup = BeautifulSoup(rel.text, "html.parser")
    inputs = soup.find('form').find_all('input')
    rel = session.post(judge_url + 'users/sign_in', data={
        inputs[0].attrs['name']: inputs[0].attrs['value'],
        inputs[1].attrs['name']: inputs[1].attrs['value'],
        'user[username]': TIOJusername,
        'user[password]': TIOJpassword,
        'user[remember_me]': '1',
        'commit': 'Sign in'
    })
    if len(session.cookies) == 1:
        print('\t\t\t\t\tFail!')
        exit(0)
    print('\t\t\t\t\tSuccess!')

def empty_prob():
    print('Creating problem...')
    new_prob_url = judge_url + 'problems/new'
    new_prob_post_url = judge_url + 'problems'
    rel = session.get(new_prob_url)
    soup = BeautifulSoup(rel.text, "html.parser")
    inputs = soup.find('form').find_all('input')
    rel = session.post(new_prob_post_url, data={
        inputs[0].attrs['name']: inputs[0].attrs['value'],
        inputs[1].attrs['name']: inputs[1].attrs['value'],
        'problem[name]': '',
        'problem[visible_state]': '2',
        'problem[problem_type]': '0',
        'problem[tag_list]': '',
        'problem[group]': '',
        'problem[description]': '',
        'problem[input]': '',
        'problem[output]': '',
        'problem[example_input]': '',
        'problem[example_output]': '',
        'problem[hint]': '',
        'problem[source]': '',
        'commit': 'Create Problem'
    }, allow_redirects=True)
    print('\t\t\t\t\tDone! (id: %s)' % rel.url.split('/')[-1])
    return rel.url.split('/')[-1]

def edit_prob(problem_code, problem_id, group=''):
    print('Uploading problem description...')
    edit_prob_url = judge_url + 'problems/%s/edit' % problem_id
    edit_prob_post_url = judge_url + 'problems/%s' % problem_id
    rel = session.get(edit_prob_url)
    soup = BeautifulSoup(rel.text, "html.parser")
    inputs = soup.find('form').find_all('input')

    with open(problem_code + '/problem.json') as json_file:
        metadata = json.load(json_file)
    
    problem_type = '0'
    if metadata['has_checker']:
        problem_type = '1'
    if metadata['has_grader']:
        if metadata['has_checker']:
            print('Conflict! has_grader and has_checker should not be true at the same time!')
            exit(0)
        problem_type = '2'

    if problem_type == '0':
        print('Using Batch Judge')
    elif problem_type == '1':
        print('Using Special Judge')
    else: 
        print('Using Interactive Judge')

    if not args.nosample:
        # Sample inputs
        if problem_type == '2':
            sample_inputs = glob.glob(problem_code + '/public/examples/*.in')
        else:
            sample_inputs = glob.glob(problem_code + '/tests/0-*.in')
        sample_inputs.sort()

        sample_input_content = ''
        if len(sample_inputs) == 1:
            sample_input_content += Path(sample_inputs[0]).read_text()
        else:
            cnt = 0
            for inp in sample_inputs:
                cnt += 1
                if cnt != 1:
                    sample_input_content += '\n'
                sample_input_content += '// Sample input %d\n' % cnt
                sample_input_content += Path(inp).read_text()
        tmp = sample_input_content.split('\n')
        for i, s in enumerate(tmp):
            p = 0
            while p < len(s):
                if s[p] != ' ':
                    break
                p += 1
            tmp[i] = s[:p].replace(' ', '&nbsp;') + s[p:]
        sample_input_content = '\n'.join(tmp)

        # Sample outputs
        if problem_type == '2':
            sample_outputs = glob.glob(problem_code + '/public/examples/*.out')
        else:
            sample_outputs = glob.glob(problem_code + '/tests/0-*.out')
        sample_outputs.sort()

        sample_output_content = ''
        if len(sample_outputs) == 1:
            sample_output_content += Path(sample_outputs[0]).read_text()
        else:
            cnt = 0
            for inp in sample_outputs:
                cnt += 1
                if cnt != 1:
                    sample_output_content += '\n'
                sample_output_content += '// Sample output %d\n' % cnt
                sample_output_content += Path(inp).read_text()
        tmp = sample_output_content.split('\n')
        for i, s in enumerate(tmp):
            p = 0
            while p < len(s):
                if s[p] != ' ':
                    break
                p += 1
            tmp[i] = s[:p].replace(' ', '&nbsp;') + s[p:]
        sample_output_content = '\n'.join(tmp)

    solution = ''

    if os.path.isfile(problem_code + '/tutorial/tutorial.md'):
        solution += Path(problem_code + '/tutorial/tutorial.md').read_text().replace('^', '^ ')
        
    solution += '\n### Solution Code\n'
    solution += '```cpp=\n'
    solution += Path(problem_code + '/solution/sol.cpp').read_text().replace(problem_code + '.h', 'lib%04d.h' % int(problem_id))
    solution += '```'
    
    data={
        inputs[0].attrs['name']: inputs[0].attrs['value'],
        inputs[1].attrs['name']: inputs[1].attrs['value'],
        inputs[2].attrs['name']: inputs[2].attrs['value'],
        'problem[name]': metadata['title'].replace('^', '^ '),
        'problem[problem_type]': problem_type,
        'problem[tag_list]': '',
        'problem[group]': group,
        'problem[description]': Path(problem_code + '/statement/description.md').read_text().replace('^', '^ ').replace(problem_code + '.h', 'lib%04d.h' % int(problem_id)),
        'problem[input]': Path(problem_code + '/statement/input.md').read_text().replace('^', '^ ').replace(problem_code + '.h', 'lib%04d.h' % int(problem_id)),
        'problem[output]': Path(problem_code + '/statement/output.md').read_text().replace('^', '^ ').replace(problem_code + '.h', 'lib%04d.h' % int(problem_id)),
        'problem[hint]': '',
        'problem[source]': Path(problem_code + '/statement/source.md').read_text(),
        'problem[solution]': solution,
        'commit': 'Update Problem'
    }
    
    if not args.nostate:
        data['problem[visible_state]'] = '2'
    
    if not args.nosample:
        data['problem[example_input]'] = sample_input_content,
        data['problem[example_output]'] = sample_output_content,
    
    rel = session.post(edit_prob_post_url, data)
    print('\t\t\t\t\tDone!')

def upload_range(problem_code, problem_id):
    print('Uploading subtasks range...')
    testdata_url = judge_url + '/problems/%s/testdata' % problem_id
    rel = session.get(testdata_url)
    soup = BeautifulSoup(rel.text, "html.parser")
    tr = soup.find_all('tr')
    data_idmap = dict()
    for i in range(1, len(tr)):
        td = tr[i].find_all('td')
        data_idmap[td[1].text.split('.')[0]] = td[0].text

    edit_prob_url = judge_url + 'problems/%s/edit' % problem_id
    edit_prob_post_url = judge_url + 'problems/%s' % problem_id
    rel = session.get(edit_prob_url)
    soup = BeautifulSoup(rel.text, "html.parser")
    inputs = soup.find('form').find_all('input')
    mapping = get_data_mapping(problem_code)
    data = {
        inputs[0].attrs['name']: inputs[0].attrs['value'],
        inputs[1].attrs['name']: inputs[1].attrs['value'],
        inputs[2].attrs['name']: inputs[2].attrs['value'],
        'commit': 'Update Problem'
    }
    with open(problem_code + '/subtasks.json') as json_file:
        subtasks_json = json.load(json_file)

    for sub in subtasks_json['subtasks']:
        index = subtasks_json['subtasks'][sub]['index']
        constraints = subtasks_json['subtasks'][sub]['text'].replace('^', '^ ')
        score = str(subtasks_json['subtasks'][sub]['score'])
        lists = []
        for test in sorted(list(mapping.tests_map[sub])):
            if test in data_idmap:
                lists.append(data_idmap[test])
            else:
                print('Missing %s!' % test)
        data['problem[testdata_sets_attributes][%d][td_list]' % index] = ','.join(lists)
        data['problem[testdata_sets_attributes][%d][constraints]' % index] = constraints
        data['problem[testdata_sets_attributes][%d][score]' % index] = score
    
    rel = session.post(edit_prob_post_url, data)
    print('\t\t\t\t\tDone!')

def clean_range(problem_id):
    print('Cleaning subtasks range...')
    edit_prob_url = judge_url + 'problems/%s/edit' % problem_id
    edit_prob_post_url = judge_url + 'problems/%s' % problem_id
    rel = session.get(edit_prob_url)
    soup = BeautifulSoup(rel.text, "html.parser")
    inputs = soup.find('form').find_all('input')
    data = {
        inputs[0].attrs['name']: inputs[0].attrs['value'],
        inputs[1].attrs['name']: inputs[1].attrs['value'],
        inputs[2].attrs['name']: inputs[2].attrs['value'],
        'commit': 'Update Problem'
    }
    for inp in inputs:
        if inp.get('name').find('testdata_sets_attributes') != -1:
            if inp.get('name').find('_destroy') != -1:
                data[inp.get('name')] = "true"
            else:
                data[inp.get('name')] = inp.get('value')
    rel = session.post(edit_prob_post_url, data)
    print('\t\t\t\t\tDone!')

def upload_test(problem_code, problem_id):
    print('Uploading testcases...')
    new_test_url = judge_url + 'problems/%s/testdata/new' % problem_id
    new_test_post_url = judge_url + 'problems/%s/testdata' % problem_id
    rel = session.get(new_test_url)
    soup = BeautifulSoup(rel.text, "html.parser")
    inputs = soup.find('form').find_all('input')
    input_data = glob.glob(problem_code + '/tests/*.in')
    input_data.sort()
    output_data = glob.glob(problem_code + '/tests/*.out')
    output_data.sort()

    with open(problem_code + '/problem.json') as json_file:
        metadata = json.load(json_file)

    for inp, out in zip(input_data, output_data):
        name = inp.split('/')[-1][:-3]
        print('Processing %s...' % name)
        rel = session.post(new_test_post_url, data={
            inputs[0].attrs['name']: inputs[0].attrs['value'],
            inputs[1].attrs['name']: inputs[1].attrs['value'],
            'testdatum[limit_attributes][time]': str(int(float(metadata['time_limit']) * 1000)),
            'testdatum[limit_attributes][memory]': str(int(float(metadata['memory_limit'] * 1024))),
            'testdatum[limit_attributes][output]': '65536',
            'testdatum[problem_id]': problem_id,
            'commit': 'Create Testdatum'
        }, files = {
            'testdatum[test_input]': open(inp, 'rb'),
            'testdatum[test_output]': open(out, 'rb')
        })
    print('\t\t\t\t\tDone!')

def update_test(problem_code, problem_id, flag):
    print('Updating testcases...')
    testdata_url = judge_url + '/problems/%s/testdata' % problem_id
    rel = session.get(testdata_url)
    soup = BeautifulSoup(rel.text, "html.parser")
    tr = soup.find_all('tr')
    data_idmap = dict()
    data_linkmap = dict()
    for i in range(1, len(tr)):
        td = tr[i].find_all('td')
        data_idmap[td[1].text.split('.')[0]] = td[0].text
        data_linkmap[td[1].text.split('.')[0]] = td[6].find('a')['href'].split('/')[-2]
    
    input_data = glob.glob(problem_code + '/tests/*.in')
    input_data.sort()
    output_data = glob.glob(problem_code + '/tests/*.out')
    output_data.sort()

    with open(problem_code + '/problem.json') as json_file:
        metadata = json.load(json_file)

    for inp, out in zip(input_data, output_data):
        name = inp.split('/')[-1][:-3]
        if name in data_idmap:
            print('Updating %s...' % name)
            edit_test_url = judge_url + 'problems/%s/testdata/%s/edit' % (problem_id, data_linkmap[name])
            edit_test_post_url = judge_url + 'problems/%s/testdata/%s' % (problem_id, data_linkmap[name])
            rel = session.get(edit_test_url)
            soup = BeautifulSoup(rel.text, "html.parser")
            inputs = soup.find('form').find_all('input')
            data = {
                inputs[0].attrs['name']: inputs[0].attrs['value'],
                inputs[1].attrs['name']: inputs[1].attrs['value'],
                inputs[2].attrs['name']: inputs[2].attrs['value'],
                'testdatum[limit_attributes][time]': str(int(float(metadata['time_limit']) * 1000)),
                'testdatum[limit_attributes][memory]': str(int(float(metadata['memory_limit'] * 1024))),
                'testdatum[limit_attributes][output]': '65536',
                'testdatum[limit_attributes][id]': data_idmap[name],
                'testdatum[problem_id]': problem_id,
                'commit': 'Update Testdatum'
            }
            files = {}
            if flag & 1 == 1:
                files['testdatum[test_input]'] = open(inp, 'rb')
            if flag & 2 == 2:
                files['testdatum[test_output]']: open(out, 'rb')
            rel = session.post(edit_test_post_url, data=data, files=files)
        else:
            print('Cannot find %s on judge, uploading...' % name)
            new_test_url = judge_url + 'problems/%s/testdata/new' % problem_id
            new_test_post_url = judge_url + 'problems/%s/testdata' % problem_id
            rel = session.get(new_test_url)
            soup = BeautifulSoup(rel.text, "html.parser")
            inputs = soup.find('form').find_all('input')
            rel = session.post(new_test_post_url, data={
                inputs[0].attrs['name']: inputs[0].attrs['value'],
                inputs[1].attrs['name']: inputs[1].attrs['value'],
                'testdatum[limit_attributes][time]': str(int(float(metadata['time_limit']) * 1000)),
                'testdatum[limit_attributes][memory]': str(int(float(metadata['memory_limit'] * 1024))),
                'testdatum[limit_attributes][output]': '65536',
                'testdatum[problem_id]': problem_id,
                'commit': 'Create Testdatum'
            }, files = {
                'testdatum[test_input]': open(inp, 'rb'),
                'testdatum[test_output]': open(out, 'rb')
            })

    print('\t\t\t\t\tDone!')

def clean_test(problem_id):
    print('Cleaning testcases...')
    sign_up_post_url = judge_url + 'problems/%s/testdata' % problem_id
    rel = session.get(sign_up_post_url)
    soup = BeautifulSoup(rel.text, "html.parser")
    token = soup.find('head').find('meta', {'name':'csrf-token'})['content']
    testdata = []
    for a in soup.find_all('a', href=True):
        if str(a).find('Destroy') != -1:
            testdata.append(a['href'][1:])
    for td in testdata:
        rel = session.post(judge_url + td, data={
            '_method': 'delete',
            'authenticity_token': token
        })
    print('\t\t\t\t\tDone!')

def upload_interlib(problem_code, problem_id):
    print('Uploading problem interactive library...')
    edit_prob_url = judge_url + 'problems/%s/edit' % problem_id
    edit_prob_post_url = judge_url + 'problems/%s' % problem_id
    rel = session.get(edit_prob_url)
    soup = BeautifulSoup(rel.text, "html.parser")
    inputs = soup.find('form').find_all('input')

    with open(problem_code + '/problem.json') as json_file:
        metadata = json.load(json_file)
   
    if not metadata['has_grader']:
        print('Fail! Not an interactive problem!')
        exit(0)

    rel = session.post(edit_prob_post_url, data={
        inputs[0].attrs['name']: inputs[0].attrs['value'],
        inputs[1].attrs['name']: inputs[1].attrs['value'],
        inputs[2].attrs['name']: inputs[2].attrs['value'],
        'problem[interlib]': Path(problem_code + '/grader/cpp/%s.h' % problem_code).read_text(),
        'commit': 'Update Problem'
    })
    print('\t\t\t\t\tDone!')

def upload_checker(problem_code, problem_id):
    print('Uploading problem checker...')
    edit_prob_url = judge_url + 'problems/%s/edit' % problem_id
    edit_prob_post_url = judge_url + 'problems/%s' % problem_id
    rel = session.get(edit_prob_url)
    soup = BeautifulSoup(rel.text, "html.parser")
    inputs = soup.find('form').find_all('input')

    with open(problem_code + '/problem.json') as json_file:
        metadata = json.load(json_file)
   
    if not metadata['has_checker']:
        print('Fail! Not an special judge problem!')
        exit(0)

    rel = session.post(edit_prob_post_url, data={
        inputs[0].attrs['name']: inputs[0].attrs['value'],
        inputs[1].attrs['name']: inputs[1].attrs['value'],
        inputs[2].attrs['name']: inputs[2].attrs['value'],
        'problem[sjcode]': Path(problem_code + '/checker/checker.cpp').read_text().replace('#include "testlib.h"', Path('judge_checker_testlib.h').read_text()),
        'commit': 'Update Problem'
    })
    print('\t\t\t\t\tDone!')

def upload_public(problem_code, problem_id):
    if not os.path.isfile(problem_code + '/public/file.json'):
        return
    print('Uploading public links...')
    edit_prob_url = judge_url + 'problems/%s/edit' % problem_id
    edit_prob_post_url = judge_url + 'problems/%s' % problem_id
    rel = session.get(edit_prob_url)
    soup = BeautifulSoup(rel.text, "html.parser")
    inputs = soup.find('form').find_all('input')

    hint_content = ''

    with open(problem_code + '/public/file.json') as json_file:
        file_json = json.load(json_file)

    for f in file_json:
        hint_content += '[%s](%s)\n%s\n\n' % (file_json[f]['title'].replace('^', '^ ').replace(problem_code + '.h', 'lib%04d.h' % int(problem_id)), file_json[f]['href'].replace('^', '^ ').replace(problem_code + '.h', 'lib%04d.h' % int(problem_id)), file_json[f]['description'].replace('^', '^ ').replace(problem_code + '.h', 'lib%04d.h' % int(problem_id)))

    rel = session.post(edit_prob_post_url, data={
        inputs[0].attrs['name']: inputs[0].attrs['value'],
        inputs[1].attrs['name']: inputs[1].attrs['value'],
        inputs[2].attrs['name']: inputs[2].attrs['value'],
        'problem[hint]': hint_content,
        'commit': 'Update Problem'
    })
    print('\t\t\t\t\tDone!')

def make_public(problem_code, problem_id):
    print('Making problem public...')
    edit_prob_url = judge_url + 'problems/%s/edit' % problem_id
    edit_prob_post_url = judge_url + 'problems/%s' % problem_id
    rel = session.get(edit_prob_url)
    soup = BeautifulSoup(rel.text, "html.parser")
    inputs = soup.find('form').find_all('input')

    rel = session.post(edit_prob_post_url, data={
        inputs[0].attrs['name']: inputs[0].attrs['value'],
        inputs[1].attrs['name']: inputs[1].attrs['value'],
        inputs[2].attrs['name']: inputs[2].attrs['value'],
        'problem[visible_state]': '0',
        'commit': 'Update Problem'
    })

    rel = session.get(judge_url + 'problems/%s' % problem_id + '/delsub')
    print('\t\t\t\t\tDone!')

login()

if args.new:
    with open(args.code + '/problem.json') as json_file:
        metadata = json.load(json_file)
    if 'judge_id' in metadata:
        if args.nocover:
            rt = input('The problem has a problem id %s already. Since --nocover is on, the problem id of %s will not be covered, keep going? (enter "yes" to ensure): ' % (metadata['judge_id'], args.code))
        else:
            rt = input('The problem has a problem id %s already, are you sure you want to cover it? (enter "yes" to ensure): ' % metadata['judge_id'])
        if rt != 'yes':
            exit(0)
    args.id = empty_prob()
    if not args.nocover:
        metadata['judge_id'] = args.id
        with open(args.code + '/problem.json', 'w') as f:
            json.dump(metadata, f)

if args.all:
    args.description = not args.description
    args.testcases = not args.testcases
    args.subtasks = not args.subtasks
    args.judge = not args.judge
    args.public = not args.public

if args.id == '-1':
    exit(0);
    with open(args.code + '/problem.json') as json_file:
        metadata = json.load(json_file)
    if 'judge_id' not in metadata:
        exit(0)
    args.id = metadata['judge_id']

if args.description:
    edit_prob(args.code, args.id, args.group)

if args.update == -1 and args.testcases:
    clean_test(args.id)
    upload_test(args.code, args.id)
elif args.update != -1:
    update_test(args.code, args.id, args.update)

if args.subtasks:
    clean_range(args.id)
    upload_range(args.code, args.id)

if args.judge:
    with open(args.code + '/problem.json') as json_file:
        metadata = json.load(json_file)
    if metadata['has_checker']:
        upload_checker(args.code, args.id)
    elif metadata['has_grader']:
        upload_interlib(args.code, args.id)

if args.public:
    upload_public(args.code, args.id)

if args.makepublic:
    make_public(args.code, args.id)

