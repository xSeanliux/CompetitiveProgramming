#include <iostream>
#include <map>
#include <string.h>
using namespace std;

string s, _s;
int n, k, c;
bool hasUpdated;

bool isAlpha(char c){
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}


string process(string s){
    int l = s.length();
    string res = "";
    for(int i = 0 ; i < l; i++){
        if('a' <= s[i] && s[i] <= 'z'){
            res += s[i];
        } else if('A' <= s[i] && s[i] <= 'Z'){
            res += s[i] - 'A' + 'a';
        }
    }
    return res;
}

int main(){
    while(cin >> n){
        map<string, int> dict;
        //cout << "ayo" << endl << endl;
        //dict.clear();
        if(c)
            cout << endl;
        else
            c++;
        k = 0;
        s = "";
        while(s != "EndOfText"){
            cin >> s;

            if(s != "EndOfText"){
                string currentString = "";
                int l = s.length();
                for(int i = 0 ; i < l; i++){
                    currentString += s[i];
                    if(!isAlpha(s[i]) || i == l-1){
                        _s = currentString;
                        _s = process(_s);
                        if(dict.count(_s)){
                            dict[_s]++;
                            //cout << _s << " has appeared " << dict[_s] << " times so far" << endl;
                        } else {
                            if(_s.length()){
                                dict.insert(pair<string , int>(_s, 1));
                                //cout << s << ", " << 1 << endl;
                            }
                        }
                        currentString = "";
                    }
                }

            }
        }
        //cout << "out" << endl;
        for(map<string, int>::iterator it = dict.begin(); it != dict.end(); it++){
            if(it -> second == n){
                cout << it -> first << endl;
                k++;

                //break;

            }
        }
        //cout << "k = " << k << endl;
        if(!k) cout << "There is no such word." << endl;
        dict.clear();
    }
}
