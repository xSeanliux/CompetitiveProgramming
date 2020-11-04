#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e6 + 10;
int T, N, K, go[maxN], dest[maxN];  
bool isIn[maxN], hasLoop, vis[maxN];

vector<int> vec;

bool dfs(int now){
	cout << "running dfs(" << now << ")" << endl;
	if(isIn[now]){
		cout << "FOUND LOOP" << endl;
		return true;
	} else {
		isIn[now] = true;
		vec.push_back(now);
	}
	bool b = false;
	if(go[now] != now && !vis[go[now]]){
		b |= dfs(go[now]);
	}
	dest[now] = dest[go[now]];
	cout << "dest[" << now << "] = " << dest[now] << endl;
	return b;
}

inline void solve(){
	cin >> N >> K;
	hasLoop = false;
	fill(vis, vis + N, 0);
	for(int i = 0; i < N; i++){
		cin >> go[i];
		go[i] += i;
		if(go[i] == i){
			dest[i] = i;
		}
	}
	vis[0] = vis[N - 1] = true;
	dest[N - 1] = N - 1;
	dest[0] = 0;
	fill(isIn, isIn + N, false);
	for(int i = 0; i < N; i++) cout << go[i] << " \n"[i == N - 1];
	for(int i = 1; i < N && !hasLoop; i++){
		if(!vis[i]){
			cout << "visited " << i << endl;
			vector<int>().swap(vec);
			hasLoop |= dfs(i);
			for(int v : vec){
				isIn[v] = false;
				vis[v] = true;
			}
		}
	}
	for(int i = 0; i < N; i++) cout << dest[i] << " \n"[i == N - 1];
	if(hasLoop){
		cout << "NO\n";
		return;
	}
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
