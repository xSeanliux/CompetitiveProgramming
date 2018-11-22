#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

long long int N;
/*
string takeAway(string a, string b){
    if(a.length() < b.length()) swap(a, b);
    int l1 = a.length();
    int l2 = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int borrow = 0;
    string res = "";
    for(int i = 0 ; i < l1; i++){
        if(i < l2){
            if(a[i] - borrow < b[i]){
                borrow = 1;
                res += 10 + a[i] - b[i] + '0';
            } else {
                borrow = 0;
                res += a[i] - borrow - b[i] + '0';
            }
        } else {
            if((a[i] - borrow - '0') < 0){
                borrow = 1;
                res += (10 + a[i] - borrow);
            } else {
                res += (a[i] - borrow);
                borrow = 0;
            }
        }
    }
    reverse(res.begin(), res.end());
    int l = res.length();
    bool flag = false;
    for(int i = 0; i < l; i++){
        if(res[i] == '0' && !flag){
            res = res.substr(1);
        } else if(res[i] != '0'){
            flag = true;
        }
    }
    return res;
}
*/
int main(){
    while(cin >> N){
        long long int k = (N+1)/2;
        long long int ans = 6*k*k - 9;
        printf("%lld\n", ans);
    }
}
