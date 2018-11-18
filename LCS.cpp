#include <iostream>
#include <string.h>
using namespace std;


string a, b;

int LCS(string a, string b){
    int la = a.length();
    int lb = b.length();
    int dp[la+1][lb+1];
    for(int i = 0 ; i <= la; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= lb; j++){
        dp[0][j] = 0;
    }
    for(int i = 1 ; i <= la; i++){
        for(int j = 1; j <= lb; j++){
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j-1], dp[i][j-1]);
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[la][lb];
}


int main(){
    while(cin >> a >> b){
        cout << LCS(a, b) << endl;
    }
}
