#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

string fibs[1005];

string add(string a, string b){
    if(a.length() < b.length()) swap(a, b);
    while(b.length() < a.length())
        b = '0' + b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int res, l = a.length();
    bool carry = false;
    string ret = "";
    for (int i = 0 ; i < l; i++){
        res = (a[i] - '0') + (b[i] - '0') + carry;
        if(res >= 10){
            carry = true;
            res -= 10;
        } else {
            carry = false;
        }
        ret += (char)(res + '0');
    }
    if(carry)
        ret += '1';
    reverse(ret.begin(), ret.end());
    return ret;
}

int N;

int main(){
    fibs[0] = "1";
    fibs[1] = "2";
    for(int i = 2; i <= 1000; i++){
        fibs[i] = add(fibs[i-1], fibs[i-2]);
        //cout << "a_" << i << " = " << fibs[i] << endl;
    }
    while(cin >> N){
        cout << fibs[N] <<endl;
    }
}
