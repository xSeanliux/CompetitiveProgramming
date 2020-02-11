#include <iostream>
using namespace std;

const int maxN = 2e5 + 10;

int n, c, dp[maxN][2], a[maxN], b[maxN];

int main(){
    cin >> n >> c;
    for(int i = 0; i < n - 1; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++){
        cin >> b[i];
    }
    dp[0][0] = a[0];
    dp[0][1] = b[0] + c;
    cout << "0 " << min(dp[0][0], dp[0][1]);
    for(int i = 1; i < n - 1; i++){
        dp[i][0] = a[i] + min(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = b[i] + min(dp[i - 1][0] + c, dp[i - 1][1]);
        cout << " " << min(dp[i][0], dp[i][1]);
    }
    cout << endl;
}


