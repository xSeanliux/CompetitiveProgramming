#include <utility>
#include <iostream>
#include <algorithm>
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
#define ppi pair<pii,int>
using namespace std;

const int MAXN = 50000;
const int MAXM = 500000;
int n;
ppi arr[MAXN];
int dp[MAXM+1];

bool cmp(const ppi a, const ppi b) {
	return a.ff.ss < b.ff.ss;
}

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].ff.ff >> arr[i].ff.ss >> arr[i].ss;
	}
	sort(arr, arr+n, cmp);
	for (int i = 1, j = 0; i <= MAXM; i++) {
		dp[i] = dp[i-1];
		while (j < n && arr[j].ff.ss == i)
			dp[i] = max(dp[i], dp[max((int)0, arr[j].ff.ff)] + arr[j].ss), j++;
	}
	cout << dp[MAXM] << endl;
}
