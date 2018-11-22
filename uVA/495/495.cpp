#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string a, string b){
    int l = max(a.length(), b.length());
    while(a.length() < l){
        a = '0' + a;
    }
    while(b.length() < l){
        b = '0' + b;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string res = "";
    int k, A, B;
    int carry = 0;
    for(int i = 0; i < l; i++){
        A = a[i] - '0';
        B = b[i] - '0';
        k = (A + B + carry) % 10;
        if(A + B + carry >= 10){
            carry = 1;
        } else {
            carry = 0;
        }
        res += k + '0';
    }
    reverse(res.begin(), res.end());
    if(carry) res = '1' + res;
    return res;
}


string fibs[5002];
int k;



int N;
int main(){
    fibs[0] = "0";
    fibs[1] = "1";
    for(int i = 2; i <= 5000; i++){
        fibs[i] = add(fibs[i-1], fibs[i-2]);
        //cout << "The Fibonacci number for " << i << " is " << fibs[i] << endl;
    }
    while(cin >> k){
        cout << "The Fibonacci number for " << k << " is "
 << fibs[k] << endl;    }
}
