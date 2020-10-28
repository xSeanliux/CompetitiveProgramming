#include <iostream>
using namespace std;

const int maxN = 5e5 + 326;
int tot = 1, last, K, dp[maxN];
string ans = "";

struct Node{
	int minLen, maxLen, childs[26], pa, sz, ep;
	Node(){
		minLen = maxLen = pa = 0;
		fill(childs, childs + 26, 0);
	}
} nodes[maxN];

inline void add(int c, int ind){
	int p = last, cur = last = ++tot;		
	nodes[cur].maxLen = nodes[p].maxLen + 1;
	for(; p && !nodes[p].childs[c]; p = nodes[p].pa){
		nodes[p].childs[c] = cur;
	}
	if(!p) nodes[cur].pa = 1;
	else {
		int q = nodes[p].childs[c];
		if(nodes[p].maxLen + 1 == nodes[q].maxLen) nodes[cur].pa = p;
		else {
			int nq = ++tot;
			nodes[nq] = nodes[q];
			nodes[nq].maxLen = nodes[p].maxLen + 1;	
			nodes[q].pa = nodes[cur].pa = nq;
			nodes[q].minLen = nodes[cur].minLen = nodes[nq].maxLen + 1;
			for(; p && nodes[p].childs[c] == q; p = nodes[p].pa) nodes[p].childs[c] = nq;
		}
	}
	nodes[cur].minLen = nodes[nodes[cur].pa].maxLen + 1;
}

void dfs(int u = 1){
	cout << "now at " << u << endl;
	dp[u] = 1;
	for(int i = 0; i < 26; i++){
		if(!nodes[u].childs[i]) continue;	
		cout << "going link " << (char)(i + 'a') << " from " << u << " to " << nodes[u].childs[i] << endl;
		dfs(nodes[u].childs[i]);
		dp[u] += dp[nodes[u].childs[i]];
	}
	cout << "sz(" << u << ") = " << dp[u] << endl;
}

void getAns(int u, int K){
	cout << "running " << u << ", " << K << endl;
	if(!K) return;
	K--;
	for(int i = 0; i < 26; i++){
		if(!nodes[u].childs[i]) continue;	
		if(dp[nodes[u].childs[i]] < K + 1){
			K -= dp[nodes[u].childs[i]];
		} else {
			ans += (char)(i + 'a');
			getAns(nodes[u].childs[i], K);
			return;
		}
	}
}

string s;

int main(){
	cin >> s >> K;
	for(int i = 0; i < s.length(); i++) add(s[i] - 'a', i);
	dfs();
	getAns(1, K);
	cout << "tot = " << dp[1] << endl;
	cout << ans << endl;
}
