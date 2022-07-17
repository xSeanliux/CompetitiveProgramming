#include <iostream>
using namespace std;
#define int long long
const int N = 105;
string a, b;
int n, m;
int dp[N][N], ways[N][N];
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    n = a.size(), m = b.size();
    for (int i = n - 1; i >= 0; --i)
        for (int j = m - 1; j >= 0; --j) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
                ways[i][j] = dp[i][j] == 1 ? 1 : ways[i + 1][j + 1];
            }
            if (dp[i][j + 1] >= dp[i][j]) {
                if (dp[i][j + 1] > dp[i][j])
                    ways[i][j] = 0;
                dp[i][j] = dp[i][j + 1];
                ways[i][j] += ways[i][j + 1];
            }
            if (dp[i + 1][j] >= dp[i][j]) {
                if (dp[i + 1][j] > dp[i][j])
                    ways[i][j] = 0;
                dp[i][j] = dp[i + 1][j];
                ways[i][j] += ways[i + 1][j];
            }
            if (dp[i + 1][j + 1] == dp[i][j]) {
                ways[i][j] -= ways[i + 1][j + 1];
            }
        }
    cout << dp[0][0] << ' ' << ways[0][0] << '\n';
}
