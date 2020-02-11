#include <iostream>
#include <string.h>
using namespace std;

int l, n;
string s;

int main(){
    cin >> l >> s;
    n = s.length();
    if(l > n){
        cout << 1;
        for(int i = 1; i < l; i++) cout << 0;
        return 0;;
    }
    bool isAllNine = true;
    for(char c : s){
        if(c != '9') isAllNine = false;
    }
    if(n % l){
        for(int i = 0; i < (n + l - 1) / l; i++){
            cout << 1;
            for(int j = 1; j < l; j++) cout << 0;
        }
        return 0;
    }
    if(isAllNine){
        for(int i = 0; i < n / l + 1; i++){
            cout << 1;
            for(int j = 1; j < l; j++) cout << 0;
        }
        return 0;
    }
    string res;
    for(int i = l - 1; i >= 0; i--){
        if(s[i] != '9'){
            for(int j = 0; j < i; j++){
                res += s[j];
            }
            res += s[i] + 1;
            for(int j = i + 1; j < l; j++){
                res += '0';
            }
            break;
        }
    }
    for(int i = 0; i < n/l; i++) cout << res;


}
