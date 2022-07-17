#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <utility>
#define double long double
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5e5 + 326;
vector<int> chi[maxN];

int N, p[maxN], K, maxval, sz[maxN];
stack<pii> stk;

int getSz(int u = 1){
	sz[u] = 1;
	for(int v : chi[u]) sz[u] += getSz(v);
	return sz[u];
}

void dfs(int u, double x){
	if(!chi[u].size()){ //i am leaf
		int k = 1;
		if(stk.size() && x * (sz[stk.top().F] - 1) <= 1.0){
			k = stk.top().S;
		}
		maxval = max(maxval, k);
		//cout << "ans for x = " << x << ", u = " << u << " = " << k << endl;
		return;
	}
	int k = sz[u];
	if(stk.size() && x * (sz[stk.top().F] - 1) <= sz[u]) k = stk.top().S;
	stk.emplace(u, k);
	for(int v : chi[u]) dfs(v, x);
	stk.pop();
}

inline bool can(double x){
	maxval = 0;
	dfs(1, x);
	return maxval <= K;
}

int main(){
	ericxiao
	cin >> N >> K;
	for(int i = 2; i <= N; i++){
		cin >> p[i];
		chi[p[i]].push_back(i);
	}
	getSz();
	double l = 0, r = 1, m;
	for(int i = 0; i < 20; i++){
		m = (l + r) / 2;
		if(can(m)) r = m;
		else l = m;
	}
	cout << setprecision(10) << m << endl;
}
