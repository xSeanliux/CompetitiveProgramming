#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string s;

string encode(string s){
    string ans = "";
    int l = s.length();
    string _s;
    for(int i = 0; i < l; i++){
        _s = to_string((int)(s[i]));
        //reverse(_s.begin(), _s.end());
        ans += _s;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string decode(string s){
    reverse(s.begin(), s.end());
    string ans = "";
    int l = s.length();
    string _s;
    for(int i = 0 ; i < l; i++){
        _s += s[i];
        _s += s[i+1];
        if(s[i] == '1'){ // three digits
            _s += s[i+2];
            i++;
        }
        i++;
        ans += (char)(stoi(_s));
        _s = "";
    }
    return ans;
}


int main(){
    while(getline(cin, s)){
        if(s[0] <= '9' && s[0] >= '0'){
            cout << decode(s) << endl;
        } else {
            cout << encode(s) << endl;
        }
    }
}
