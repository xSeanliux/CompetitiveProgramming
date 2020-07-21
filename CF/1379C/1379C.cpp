#include <iostream>
#include <algorithm>
#include <queue>
#define int long long int
using namespace std;

const int maxN = 2e5 + 226;
int T, N, M, a, b;
priority_queue<int, vector<int>, greater<int> > pq;

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
	pq = priority_queue<int, vector<int>, greater<int> >();
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		lines[i] = Line(b, a - b);
	}
	sort(lines, lines + M, [](Line x, Line y){
		return (x.m == y.m ? x.k < y.k : x.m < y.m);	
	});
	int sum = 0, ans = 0;
	for(int i = 0; i < M; i++){
		while(pq.size() && (pq.size() > N || pq.top() < lines[i].m)){
			sum -= pq.top();
			pq.pop();
		}
		if(pq.size() == N) ans = max(ans, sum);
		else ans = max(ans, sum + lines[i].eval(N - pq.size()));	
		sum += lines[i].eval(1);
		pq.push(lines[i].eval(1));
	}
	cout << ans << endl;
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}


