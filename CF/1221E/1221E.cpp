#include <iostream>
#include <string.h>
using namespace std;

int q, a, b, dp[300005];
string s;

int main(){
    cin >> q;
    while(q--){
        cin >> a >> b >> s;
        dp[0] = (s[0] == '.');
        bool win = false;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == 'X') dp[i] = 0;
            else dp[i] = dp[i-1] + 1;
            if(dp[i] >= b && dp[i] < a) win = true;
        }
        if(win){
            cout << "NO" << endl;
            return 0;
        }

    }
}
