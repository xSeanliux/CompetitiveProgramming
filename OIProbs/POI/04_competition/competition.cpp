#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e4 + 326, INF = 2e15;
vector<pii> adj[maxN];
pii minDist[maxN][2];

int a, b, c, d, N, M;
bool vis[maxN];

inline bool upd(int tgt, int from, int dist, pii arr[][2]){
	if(dist <= arr[tgt][0].F){
		if(arr[tgt][0].S == from){
			arr[tgt][0] = {dist, from};
		} else {
			arr[tgt][1] = arr[tgt][0];
			arr[tgt][0] = {dist, from};
		}
		return true;
	} else if(dist <= arr[tgt][1].F && from != arr[tgt][0].S){
		arr[tgt][1] = {dist, from};
		return true;
	}
	return false;
}

struct Obj{
	int now, dist, from;
	Obj(){}
	Obj(int n, int d, int f): now(n), dist(d), from(f){}
	const bool operator<(const Obj &o) const{
		return o.dist < dist;
	}
};

priority_queue<Obj> pq;

signed main(){
	ericxiao;
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> a >> b >> c >> d;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, d);
	}
	for(int i = 1; i <= N; i++){
		minDist[i][0] = minDist[i][1] =  {INF, -1};
	}
	for(auto [v, w] : adj[1]){
		pq.emplace(Obj(v, w, v));
	}
	while(pq.size()){
		Obj o = pq.top();
		int now = o.now, dist = o.dist, from = o.from;
		pq.pop();
		for(auto [to, w] : adj[now]){
			if(to == 1) continue;
			if(upd(to, from, w + dist, minDist)){
				pq.emplace(Obj(to, w + dist, from));
			}
		}
	}
	int ans = INF;
	for(int i = 2; i <= N; i++){
		for(auto [u, v] : adj[i]){
			if(u == 1){
				if(minDist[i][0].S == i){
					ans = min(ans, v + minDist[i][1].F);	
				} else {
					ans = min(ans, v + minDist[i][0].F);
				}
			}
		}
	}
	cout << ans << endl;
}
