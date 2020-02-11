#include <iostream>
#include <string.h>
using namespace std;

const int maxN = 226, INF = 1e6;

int dp[maxN][maxN][2 * maxN];
bool from[maxN][maxN][2 * maxN];

string a, b;

int main(){
    cin >> a >> b;
    a = '$' + a;
    b = '$' + b;

    for(int i = 0; i < a.length(); i++)
        for(int j = 0; j < b.length(); j++)
            for(int k = 0; k <= a.length() + b.length(); k++){
                dp[i][j][k] = INF;
            }

    for(int i = 0; i <= a.length() + b.length(); i++) dp[0][0][i] = i;

    for(int i = 0; i < a.length(); i++){
        for(int j = 0; j < b.length(); j++){
            if(!i && !j) continue;
            int ti = i, tj = j;
            for(int k = 1; k < a.length() + b.length(); k++){
                ti = i, tj = j;
                if(a[i] == '(') ti--;
                if(b[j] == '(') tj--;
                dp[i][j][k] = dp[ti][tj][k - 1] + 1;
                from[i][j][k] = 0;
            }
            for(int k = a.length() + b.length() - 1; k >= 0; k--){
                ti = i, tj = j;
                if(a[i] == ')') ti--;
                if(b[j] == ')') tj--;
                if(dp[ti][tj][k + 1] + 1 <= dp[i][j][k]) from[i][j][k] = 1;
                dp[i][j][k] = min(dp[i][j][k], dp[ti][tj][k + 1] + 1);
            }
        }
    }

    int i = a.length() - 1, j = b.length() - 1, k = 0;
    string ans = "";
    //cout << dp[i][j][k] << endl;
    while(i || j || k){
        //cout << "At i = " << i << ", j = " << j << ", k = " << k << endl;
        if(from[i][j][k]){
            k++;
            ans = ')' + ans;
            if(a[i] == ')') i--;
            if(b[j] == ')') j--;
        } else {
            k--;
            ans = '(' + ans;
            if(a[i] == '(') i--;
            if(b[j] == '(') j--;
        }
    }
    cout << ans << endl;
}
