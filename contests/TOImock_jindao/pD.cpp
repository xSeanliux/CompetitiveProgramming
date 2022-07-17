#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 3260;

const string operator+(string a, string b){
	string res = "";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if(a.length() < b.length()) swap(a, b);
	while(b.length() < a.length()) b += '0';
	int c = 0;
	for(int i = 0; i < a.length(); i++){
		int r = (a[i] + b[i] + c - 2 * '0'); 
		if(r >= 10){
			res += (r - 10 + '0');
			c = 1;
		} else {
			res += (r + '0');
			c = 0;
		}
	}
	reverse(res.begin(), res.end());
	return res;
}

const bool operator<(string &a, string &b){
	if(a.length() != b.length()){
		return a.length() < b.length();
	}
	for(int i = 0; i < a.length(); i++) if(a[i] != b[i]) return a[i] < b[i];
	return false;
}

string w[maxN], dp[maxN];
int sz[maxN], N, u, v;
vector<int> adj[maxN], chi[maxN];
vector<string> ord, ans;

int dfs(int p, int u){
	sz[u] = 1;
	vector<int>().swap(chi[u]);
	for(int v : adj[u]) if(v != p){
		chi[u].push_back(v);
		sz[u] += dfs(u, v);
	}
	sort(chi[u].begin(), chi[u].end(), [](int a, int b){
		return dp[a] > dp[b];
	});
	dp[u] = "0";
	int roll = 0;
	//cout << "chi[" << u << "] = ";
	//for(int x : chi[u]) cout << x << " ";
	//cout << endl;
	for(int c : chi[u]){
		for(int i = 0; i < roll; i++) dp[c] += '0';
		dp[u] = dp[u] + dp[c];
		roll += sz[c];
	}
	string now = w[u];
	for(int i = 0; i < roll; i++) now += '0';
	dp[u] = dp[u] + now;
	//cout << "dp[" << u << "] = " << dp[u] << endl;
	return sz[u];
}

void getAns(int u){
	ans.push_back(w[u]);	
	reverse(chi[u].begin(), chi[u].end());
	for(int v : chi[u]) getAns(v);
}

int main(){
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> w[i];
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	string mx = "";
	int minRoot = 0;
	for(int r = 1; r <= N; r++){
		//cout << "r = " << r << endl;
		dfs(r, r);
		if(mx == "" || dp[r] < mx){
			mx = dp[r];
			minRoot = r;
		}
	}
	dfs(minRoot, minRoot);
	getAns(minRoot);
	for(string x : ans) cout << x << " ";
}
