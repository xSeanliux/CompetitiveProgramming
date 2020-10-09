#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 1e6 + 10;

int deg[maxN], N, M, Q, x, a, b, ans;
vector<int> ins[maxN];

signed main(){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
		if(a > b){
			ins[b].push_back(a);
		} else {
			ins[a].push_back(b);
		}
	}
	for(int i = 1; i <= N; i++){
		ans += ins[i].size() * (deg[i] - ins[i].size());
	}
	cin >> Q;
	cout << ans << endl;
	while(Q--){
		cin >> x;
		ans -= ins[x].size() * (deg[x] - ins[x].size());
		for(int y : ins[x]){
			ans -= ins[y].size() * (deg[y] - ins[y].size());
			ins[y].push_back(x);
			ans += ins[y].size() * (deg[y] - ins[y].size());
		}
		vector<int>().swap(ins[x]);
		cout << ans << endl;
	}
}
