#include <iostream>
#include <vector>
#include <fstream>
#define int long long int
using namespace std;

string _dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/uniqsubstr/", dir;

ifstream infile;
ofstream outfile;

const int maxN = 3e5 + 326, W = 26;

struct Node{
	int childs[W], fa, len;	
	Node(){
		fill(childs, childs + W, 0);
		fa = len = 0;
	}
} nodes[maxN];

int cnt = 1, last = 1, dp[maxN];

string s;

void add(int c){
	int p = last;
	int cur = last = ++cnt;
	nodes[cur].len = nodes[p].len + 1;
	for(; p && !nodes[p].childs[c]; p = nodes[p].fa) nodes[p].childs[c] = cur;
	if(!p) nodes[cur].fa = 1;
	else {
		int q = nodes[p].childs[c];
		if(nodes[q].len == nodes[p].len + 1) nodes[cur].fa = q;
		else {
			int nq = ++cnt;
			nodes[nq] = nodes[q];
			nodes[nq].len = nodes[p].len + 1;
			nodes[q].fa = nodes[cur].fa = nq;
			for(; p && nodes[p].childs[c] == q; p = nodes[p].fa) nodes[p].childs[c] = nq;
		}
	}
}

/*
void dfs(int now, int lvl = 0){
	for(int i = 0; i < W; i++) if(nodes[now].childs[i]){
		for(int i = 0; i < lvl; i++) cout << '\t'; 
		cout << (char)(i + 'a') << ": " << dp[now] << endl;
		dfs(nodes[now].childs[i], lvl + 1);
	}
}
*/

int getAns(int now = 1){
	if(dp[now]) return dp[now];
	dp[now] = 1;
	for(int i = 0; i < W; i++){
		if(nodes[now].childs[i]) dp[now] += getAns(nodes[now].childs[i]);
	}
	return dp[now];
}

void run(string s){
	for(char c : s) add(c - 'a');	
	outfile << getAns() << endl; 
	fill(dp, dp + cnt + 1, 0);
	fill(nodes, nodes + cnt + 1, Node());
	cnt = last = 1;
}

inline void solve(string folder, int tc){
	dir = _dir + folder + "/" + to_string(tc); 
	cout << "opening: " << dir << endl;
	outfile.open(dir + ".out");
	infile.open(dir + ".in");
	while(infile >> s){
		run(s);	
	}
	infile.close();
	outfile.close();
	cout << "Solved: " << folder << " / " << tc << endl;
}

signed main(){
	for(int t = 11; t <= 15; t++) solve("alltest", t);
}
