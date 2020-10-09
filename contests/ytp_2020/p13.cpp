#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int MAXN = 500000;
const int INF = 1e18;
int n, m, k;
int a, b, c;
int ans = INF;
vector <pii> path[MAXN+1];
priority_queue <pii, vector<pii>, greater<pii>> nxt;
int S[MAXN+1];
int T[MAXN+1];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i <= n; i++) {
		S[i] = T[i] = INF;
	}
	S[1] = 0, T[n] = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		path[a].pb(pii(b, c));
		path[b].pb(pii(a, c));
	}
	nxt.push(pii(0, 1));
	while (nxt.size()) {
		int now = nxt.top().ss, dis = nxt.top().ff;
		for (pii e : path[now]) {
			if (dis + e.ss < S[e.ff]) {
				S[e.ff] = dis + e.ss;
				nxt.push(pii(dis + e.ss, e.ff));
			}
		}
		nxt.pop();
	}
	nxt.push(pii(0, n));
	while (nxt.size()) {
		int now = nxt.top().ss, dis = nxt.top().ff;
		for (pii e : path[now]) {
			if (dis + e.ss < T[e.ff]) {
				T[e.ff] = dis + e.ss;
				nxt.push(pii(dis + e.ss, e.ff));
			}
		}
		nxt.pop();
	}
	ans = T[1];
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c;
		ans = min(ans, S[a] + T[b] + c);
		ans = min(ans, S[b] + T[a] + c);
	}
	if (ans < INF) cout << ans << "\n";
	else cout << -1 << "\n";
}
