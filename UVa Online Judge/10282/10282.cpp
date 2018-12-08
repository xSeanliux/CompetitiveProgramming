#include <iostream>
#include <string.h>
#include <map>
using namespace std;

map <string, string> dict;
string s;

int main(){
    while(getline(cin, s)){
        if(s == "")
            break;
        int l = s.length(), i;
        for(i = 0; i < l; i++){
            if(s[i] == ' ') break;
        }
        string a = s.substr(0, i);
        string b = s.substr(i + 1, l);
        dict.insert(pair<string, string>(b, a));
    }
    while(cin >> s){
        if(dict.count(s)){
            cout << dict[s] << endl;
        } else {
            cout << "eh" << endl;
        }
    }
}
