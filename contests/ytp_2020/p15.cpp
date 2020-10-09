#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define int long long
using namespace std;

const int MAXN = 300000;
const int L = 20;
int n, q;
int cnt;
int a, b, c;
int anc[MAXN+1][L];
pii dfs[MAXN+1];
vector <pii> path[MAXN+1];

struct node{
	int pre, suf, mmax, sum;
	node(int val) {
		sum = val;
		pre = suf = mmax = max((int)0, val);
	}
	node() {}
} arr[MAXN+1][L];

void DFS(int now, int par) {
	dfs[now].ff = ++cnt;
	for (pii e : path[now]) {
		if (e.ff != par) {
			DFS(e.ff, now);
			anc[e.ff][0] = now;
			arr[e.ff][0] = node(e.ss);
		}
	}
	dfs[now].ss = ++cnt;
}

node Merge(node a, node b) {
	node m;
	m.pre = max(a.pre, a.sum + b.pre);
	m.suf = max(a.suf + b.sum, b.suf);
	m.sum = a.sum + b.sum;
	m.mmax = max({a.mmax, b.mmax, a.suf + b.pre});
	return m;
}

void init() {
	for (int p = 1; p < L; p++) {
		for (int i = 1; i <= n; i++) {
			anc[i][p] = anc[anc[i][p-1]][p-1];
			arr[i][p] = Merge(arr[i][p-1], arr[anc[i][p-1]][p-1]);
		}
	}
}

bool ancestor(int a, int b) {
	return (dfs[a].ff <= dfs[b].ff && dfs[a].ss >= dfs[b].ss);
}

int solve(int a, int b) {
	node A(0), B(0);
	if (!ancestor(a, b)) {
		for (int p = L-1; p >= 0; p--) {
			if (!ancestor(anc[a][p], b)) {
				A = Merge(A, arr[a][p]);
				a = anc[a][p];
			}
		}
		A = Merge(A, arr[a][0]);
	}
	if (!ancestor(b, a)) {
		for (int p = L-1; p >= 0; p--) {
			if (!ancestor(anc[b][p], a)) {
				B = Merge(B, arr[b][p]);
				b = anc[b][p];
			}
		}
		B = Merge(B, arr[b][0]);
	}
	return max({A.mmax, B.mmax, A.suf + B.suf});
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		path[a].pb(pii(b, c));
		path[b].pb(pii(a, c));
	}
	anc[1][0] = 1, arr[1][0] = node(0);
	DFS(1, 0);
	init();
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
}
