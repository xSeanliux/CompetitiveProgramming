#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

string s;

int main(){
    while(getline(cin, s)){
        if(s == "END") return 0;
        string cs = "";
        vector<string> strs;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                strs.push_back(cs);
                cs = "";
            } else {
                cs += s[i];
                if(i == s.length() - 1) strs.push_back(cs);
            }
        }
        for(string s : strs) cout << (char)(s[0] - 'a' + 'A');
        cout << " " << *strs.rbegin() << endl;
    }
}
