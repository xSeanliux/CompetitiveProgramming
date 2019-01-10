#include <iostream>
#include <string.h>
using namespace std;

int a, b;
string s;

bool check(string s){
    int l = s.length();
    a = 0, b = 0;
    for(int i = 0 ; i < l; i++){
        if(i % 2){
            a += s[i] - '0';
        } else {
            b += s[i] - '0';
        }
    }
    if(!((max(a, b) - min(a, b)) % 11)) return true;
    return false;
}

int main(){
    string ans;
    while(cin >> s){
        if(s == "0") return 0;
        else{
            ans = (check(s)) ? " is a multiple of 11.\n" : " is not a multiple of 11.\n";
            cout << s << ans;
        }
    }
}
