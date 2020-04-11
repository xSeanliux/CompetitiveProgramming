#include <iostream>
#include <string.h>
using namespace std;

int q, N;
string s;

void solve(){
    cin >> N >> s;
    string a, b;
    bool f = true;
    for(char c : s){
        if(c == '0'){
            a += '0';
            b += '0';
        } else if(c == '2'){
            if(f){
                a += '1';
                b += '1';
            } else {
                a += '0';
                b += '2';
            }

        } else {
            if(f){
                a += '1';
                b += '0';
                f = false;
            } else {
                a += '0';
                b += '1';
            }
        }
    }
    cout << a << endl << b << endl;
}

int main(){
    cin >> q;
    while(q--){
        solve();
    }
}
