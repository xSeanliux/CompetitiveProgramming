#include <iostream>
#include <algorithm>
#include <string.h>
#define M 100
using namespace std;

string choose[M + 10][M + 10];
int N, K;


string add(string a, string b){
    if(a.length() < b.length()) swap(a, b);
    while(b.length() < a.length())
        b = '0' + b;
    bool carry = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int l = a.length();
    string ans = "";
    for(int i = 0 ; i < l; i++){
        int res = a[i] - '0' + b[i] - '0' + carry;
        if(res >= 10){
            carry = true;
            ans += (char)((res - 10) + '0');
        } else {
            carry = false;
            ans += (res + '0');
        }
    }
    if(carry)
        ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    for(int i = 1; i <= M; i++){
        choose[i][0] = choose[i][i] = "1";
    }
    for(int i = 2; i <= M; i++){
        for(int j = 1; j < i; j++){
            choose[i][j] = add(choose[i-1][j], choose[i-1][j-1]);
            //cout << "Choose[" << i << ", " << j << "] = " << choose[i][j] << endl;
        }
    }
    while(cin >> N >> K){
        if(!N && !K) return 0;
        printf("%d things taken %d at a time is %s exactly.\n", N, K, choose[N][K].c_str());
    }
}
