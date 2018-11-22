#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#define MAX 201
using namespace std;
int N, K;
string C[201][201];

string add(string a, string b){
    if(a.length() < b.length()) swap(a, b);
    while(b.length() < a.length()) b = '0' + b;
    int l = (int)a.length(); //mod 10e6
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string res = "";
    bool carry = false;
    int _r;
    for(int i = 0 ; i < l; i++){
        _r = (a[i] - '0') + (b[i] - '0') + carry;
        if(_r >= 10){
            res += (_r % 10) + '0';
            carry = true;
        } else {
            res += _r + '0';
            carry = false;
        }
    }
    if(carry)
        res += '1';
    reverse(res.begin(), res.end());
    return res;
}

void computeC(){
    for(int i = 0 ; i < MAX; i++){
        C[i][0] = C[i][i] = "1";
    }
    for(int i = 1; i < MAX; i++){
        for(int j = 1; j < i; j++){
            C[i][j] = add(C[i-1][j], C[i-1][j-1]);
        }
    }
}


int main(){ //ans: N + (K - 1) choose (K - 1)
    computeC();
    while(cin >> N >> K){
        if(!N & !K)
            return 0;
        else{
            string ans = C[N + K - 1][K - 1];
            int l = ans.length();
            if(l > 5)
                ans = ans.substr(l - 6);
            while(ans[0] == '0'){
                ans = ans.substr(1);
            }
            cout << ans << endl;

        }

    }
}
