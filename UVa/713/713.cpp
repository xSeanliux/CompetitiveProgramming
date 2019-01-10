#include <iostream>
#include <string.h>
using namespace std;

int T;
string a, b;

string revAdd(string a, string b){
    if(a.length() < b.length()) swap(a, b);
    while(b.length() < a.length()) b += '0';
    int l = a.length();
    bool carry = false;
    string res = "";
    for(int i = 0 ; i < l; i++){
        if(a[i] - '0' + b[i] - '0' + carry > 9){
            res += (char)(a[i] - '0' + b[i] + carry - 10);
            carry = true;
        } else {
            res += (char)(a[i] - '0' + b[i] + carry);
            carry = false;
        }
    }
    if(carry) res += '1';
    while(res[0] == '0') res = res.substr(1);
    return res;
}

int main(){
    cin >> T;
    while(T--){
        cin >> a >> b;
        cout << revAdd(a, b) << endl;
    }
}
