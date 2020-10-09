#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 2e5 + 226;
int T, N, M, a, b;
bool isIn[maxN];
priority_queue<pii, vector<pii>, greater<pii> > pq;

struct Line{
	int m, k;
	Line(){}
	Line(int m, int k): m(m), k(k){}
	int eval(int x){
		return m * x + k;
	}
} lines[maxN];

inline void solve(){
	cin >> N >> M;
	pq = priority_queue<pii, vector<pii>, greater<pii> >();
	int sum = 0, ans = 0;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		isIn[i] = true;
		lines[i] = Line(b, a - b);
		sum += a;
	}
	sort(lines, lines + M, [](Line x, Line y){
		return (x.m < y.m);	
	});
	for(int i = 0; i < M; i++){
		pq.push({lines[i].eval(1), i});
	}
	for(int i = 0; i < M; i++){
		while(pq.size() && (pq.size() >= N || pq.top().F < lines[i].m)){
			auto [val, ind] = pq.top();
			pq.pop();
			sum -= val;
			isIn[ind] = false;
		}
		if(isIn[i]){
			ans = max(ans, sum + (N - (int)pq.size()) * lines[i].m);	
		} else {
			ans = max(ans, sum + lines[i].eval(N - (int)pq.size()));
		}
	}
	cout << ans << endl;
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}


