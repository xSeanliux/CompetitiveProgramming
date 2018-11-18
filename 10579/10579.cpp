#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> fib;
int ind;

string add(string a, string b){
    if(a.length() < b.length()) swap(a, b);
    while(b.length() < a.length()) b = '0' + b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int l = a.length();
    bool carry = 0;
    string res = "";
    for(int i = 0; i < l; i++){
        if((a[i] - '0') + (b[i] - '0') + carry > 9){
            res += (((a[i] - '0') + (b[i] - '0') + carry) % 10) + '0';
            carry = 1;
        } else {
            res += ((a[i] - '0') + (b[i] - '0') + carry) + '0';
            carry = 0;
        }
    }
    if(carry)
        res += '1';
    reverse(res.begin(), res.end());
    return res;
}


int main(){
    fib.push_back("1");
    fib.push_back("1");

    //cout << add("13", "13") << endl;
    //cout << add("8", "13") << endl;
    for(int i = 2; fib[i-1].length() <= 1000; i++){
        fib.push_back(add(fib[i-1], fib[i-2]));
        //cout << "fib[" << i << "] = " << fib[i] << " = " << add(fib[i-1], fib[i-2]) << " = " << fib[i-1] << " + " << fib[i-2]<< endl;
        //fib[i] = add(fib[i-1], fib[i-2]);
    }

    while(cin >> ind){
        cout << fib[ind-1] << endl;
    }
}
