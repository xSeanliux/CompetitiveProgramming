#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

map <string, vector<string> > arr;
vector <string> toOutput;
string s;

string toLower(string s){
    string res = "";
    int l = s.length();
    for(int i = 0 ; i < l; i++){
        if(s[i] <= 'z' && s[i] >= 'a'){
            res += s[i];
        } else if(s[i] <= 'Z' && s[i] >= 'A'){
            res += (char)(s[i] - 'A' + 'a');
        }
    }
    return res;
}

int main(){
    while(cin >> s){
        if(s == "#"){
            toOutput.empty();
            for(map<string, vector<string> >::iterator x = arr.begin(); x != arr.end(); ++x){
                if((x -> second).size() == 1){
                    for(int i = 0 ; i < (x->second).size(); i++){
                        toOutput.push_back((x->second)[i]);
                    }
                }
            }
            sort(toOutput.begin(), toOutput.end());
            for(int i = 0 ; i < toOutput.size(); i++){
                cout << toOutput[i] << endl;
            }
            return 0;
        }
        string newS = toLower(s);
        sort(newS.begin(), newS.end());
        //cout << "newS: " << newS << endl;
        if(arr.count(newS)){
            arr[newS].push_back(s);
            //cout << "Old word: " << newS << endl;
            //cout << "new Size: " << arr[newS].size() << endl;
        } else {
            vector<string> _v;
            _v.push_back(s);
            //cout << "New word: " << newS << endl;
            arr.insert(pair<string, vector<string> >(newS, _v));
        }
    }
}



