#include <iostream>
#include <queue>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 226;

int N, a[maxN], b[maxN], indeg[maxN], ans;
queue<int> que;
vector<int> bef[maxN], aft[maxN], roots, ord;

void dfs(int x){
	for(int u : bef[x]) dfs(u);
	ord.push_back(x);
	for(int u : aft[x]) dfs(u);
}

signed main(){
	ericxiao;
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	for(int i = 1; i <= N; i++){
		cin >> b[i];
		if(~b[i]) indeg[b[i]]++;
	}
	for(int i = 1; i <= N; i++) if(!indeg[i]) que.push(i);
	while(que.size()){
		int x = que.front();
		que.pop();
		ans += a[x];
		if(~b[x]){
			if(a[x] >= 0){
				bef[b[x]].push_back(x);
				a[b[x]] += a[x];
			} else {
				aft[b[x]].push_back(x);
			}
			indeg[b[x]]--;
			if(!indeg[b[x]]) que.push(b[x]);
		} else {
			roots.push_back(x);
		
	}
	for(int st : roots) dfs(st);
	cout << ans << endl;
	for(int x : ord) cout << x << " ";
	cout << endl;
}
