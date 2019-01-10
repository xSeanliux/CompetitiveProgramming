#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
string s;
int T, l, dp[1005][1005];

int getRes(int a, int b){
    //cout << "Running dp(" << a << ", " << b << ")" << endl;
    if(dp[a][b]){
        return dp[a][b];
    } else if(a == b){
        dp[a][b] = 1;
    } else if(b - a == 1){
        dp[a][b] = 1 + (s[a] == s[b]);
    } else if(s[a] == s[b]){
        dp[a][b] = getRes(a+1, b-1) + 2;
    } else {
        dp[a][b] = max(getRes(a+1, b), getRes(a, b-1));
    }
    //cout << "dp[" << a << "][" << b << "] = " << dp[a][b] << endl;
    return dp[a][b];
}

int main(){
    cin >> T;
    getline(cin, s);
    while(T--){
        getline(cin, s);
        if(s == ""){
            cout << 0 << endl;
            continue;
        }
        l = s.length();
        for(int i = 0 ; i < l; i++)
            for(int j = 0; j < l; j++)
                dp[i][j] = 0;
        cout << getRes(0, l-1) << endl;
        //cout << dp[0][l-1] << endl;v
    }
}
