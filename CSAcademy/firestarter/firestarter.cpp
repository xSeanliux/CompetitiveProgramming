#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

const int maxN = 2e5 + 326, INF = 1e15;
int N, M, Q, u[maxN], v[maxN], w[maxN], ans[maxN], a, b, t, x, edgeAns[maxN], ANS;
unordered_map<int, int> adj[maxN];

inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

inline void const Read(int & p) {
	p = 0;
	int tmp = 0;
	char c = readchar();
	tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	p = tmp?-p:p;
}

struct Que{
	int t, d;
	Que(){}
	Que(int t, int d): t(t), d(d){}
	inline bool operator<(const Que &q) const {
		return d < q.d;
	}
};


vector<Que> ques[maxN];


priority_queue<pii, vector<pii>, greater<pii>> pq;
bool vis[maxN];

inline bool can(int id, int t){
	//cout << "checking id = " << id << endl;
	//cout << "t = " << t << endl;
	sort(ques[id].begin(), ques[id].end(), [=](Que a, Que b){
		return a.d - (t - a.t) < b.d - (t - b.t);
	});
	int r = 0, _l, _r;
	for(Que q : ques[id]){
		//cout << "for t = " << q.t << ", d = " << q.d << endl;
		if(q.t > t) continue;
		_l = max(0LL, q.d - (t - q.t));
		_r = min(w[id], q.d + (t - q.t));
		//cout << "l = " << _l << ", r = " << _r << endl;
		if(_l > r) return false;
		r = max(r, _r);
		if(r == w[id]) return true;
	}
	return false;
}

signed main() {
	ericxiao
	Read(N);
	Read(M);
	Read(Q);
	fill(ans, ans + N + 1, INF);
	fill(edgeAns, edgeAns + M + 1, INF);
    for(int i = 0; i < M; i++){
		Read(u[i]);
		Read(v[i]);
		Read(w[i]);
		if(u[i] > v[i]) swap(u[i], v[i]);
		w[i] *= 2;
        adj[v[i]][u[i]] = adj[u[i]][v[i]] = i;
    }
    while(Q--){
		Read(t);
		Read(a);
		Read(b);
		Read(x);
		t *= 2;
		x *= 2;
		if(a > b){
			swap(a, b);
			x = w[adj[a][b]] - x;
		}
		ques[adj[a][b]].emplace_back(t, x);
		ans[a] = min(ans[a], t + x);	
		ans[b] = min(ans[b], t + w[adj[a][b]] - x);
		//cout << "ans[" << a << "] = " << ans[a] << ", ans[" << b << "] = " << ans[b] << endl;
    }
	for(int i = 1; i <= N; i++){
		if(ans[i] < INF) pq.push({ans[i], i});
	}
	int cnt = 0;
	while(pq.size() && cnt < N){
		auto [d, u] = pq.top();
		pq.pop();
		if(vis[u]) continue;
		vis[u] = true;
		cnt++;
		ANS = max(ANS, ans[u]);
		for(auto [v, id] : adj[u]){
			if(vis[v]) continue;
			if(ans[v] > w[id] + d){
				ans[v] = w[id] + d;
				pq.push({ans[v], v});
			}
		}
	}
	for(int i = 0; i < M; i++){
		ques[i].emplace_back(ans[u[i]], 0);
		ques[i].emplace_back(ans[v[i]], w[i]);
		int t = 0;
		for(int l = (1LL << 60); l; l >>= 1) if(!can(i, t + l)) t += l;
		ANS = max(ANS, t + 1);
	}
	cout << (ANS / 2) << "." << (ANS & 1 ? "5" : "0")  << endl;
}


