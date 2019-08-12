#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string add(string a, string b){
    if(a.length() < b.length()) swap(a, b);
    while(b.length() < a.length()) b = '0' + b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    bool carry = false;
    int _t;
    string res = "";
    for(int i = 0; i < a.length(); i++){
        _t = a[i] - '0' + b[i] - '0';
        if(_t + carry >= 10){
            res += (_t + carry - 10) + '0';
            carry = true;
        } else {
            res += (_t + carry) + '0';
            carry = false;
        }
    }
    if(carry) res += '1';
    reverse(res.begin(), res.end());
    return res;
}

string oneMult(string a, int b){
    string res = "";
    int carry = 0;
    reverse(a.begin(), a.end());
    for(int i = 0; i < a.length(); i++){
            res += (((a[i] - '0') * b + carry) % 10) + '0';
            carry = ((a[i] - '0') * b + carry)/10;
    }
    if(carry) res += (carry + '0');
    reverse(res.begin(), res.end());
    return res;
}

string mult(string a, string b){
    string res = "0", _res;
    reverse(b.begin(), b.end());
    for(int i = 0; i < b.length(); i++){
        _res = oneMult(a, b[i] - '0');
        for(int j = 0; j < i; j++){
            _res += '0';
        }
        res = add(res, _res);
    }
    return res;
}

string a, b, r;

int main(){
    while(cin >> a >> b){
        r = mult(a, b);
        while(r[0] == '0'){
            r = r.substr(1);
        }
        if(r == "") r = "0";
        cout << r << endl;
    }
}
