#include <iostream>
#include <string.h>
using namespace std;

string s1, op, s2;
int C;

int hexToDec(string s){
    int ans = 0, l = s.length();
    for(int i = 0 ; i < l; i++){
        ans *= 16;
        if(s[i] <= '9' && s[i] >= '0')
            ans += s[i] - '0';
        else
            ans += s[i] - 'A' + 10;

    }
    return ans;
}

string decToBin(int N){
    string res = "";
    while(N){
        res = (char)((N % 2) + '0') + res;
        N /= 2;
    }
    while(res.length() < 13) res = '0' + res;
    return res;
}



int main(){
    cin >> C;
    while(C--){
        cin >> s1 >> op >> s2;
        int res1 = hexToDec(s1), res2 = hexToDec(s2), ans;
        if(op == "+") ans = res1 + res2;
        else if(op == "-") ans = res1 - res2;
        string bin1 = decToBin(res1), bin2 = decToBin(res2);
        cout << bin1 << " " << op << " " << bin2 << " = " << ans << endl;
    }
}
