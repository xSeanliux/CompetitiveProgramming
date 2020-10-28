#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 326, INF = 1e6;

int N, take[maxN], frq[maxN];
string t, s[maxN];

struct Flow{
	int cap[maxN][maxN], cost[maxN][maxN];
	int from[maxN], minD[maxN];
	bool visited[maxN];
	priority_queue<pii, vector<pii>, greater<pii>> pq;		
	Flow(){
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++){
				cap[i][j] = 0;
			}
	}
	inline void addEdge(int u, int v, int c, int f){
		cap[u][v] = f;
		cap[v][u] = 0;
		cost[u][v] = c;
		cost[v][u] = -c;
	}
	inline bool SP(int s, int t){
		pq = priority_queue<pii, vector<pii>, greater<pii>>();
		fill(minD, minD + maxN, INF);
		fill(from, from + maxN,  -1);
		fill(visited, visited + maxN, false);
		minD[s] = 0;
		pq.push({0, s});
		while(pq.size()){
			auto [d, u] = pq.top();
			//cout << "now at " << u << endl;
			visited[u] = true;
			pq.pop();
			for(int i = 1; i < maxN; i++){
				if(!visited[i] && cap[u][i] > 0 && cost[u][i] + d < minD[i]){
					minD[i] = cost[u][i] + d;
					pq.push({minD[i], i});
					from[i] = u;
				}
			}
		}
		//cout << "from[t] = " << from[t] << endl;
		return from[t] != -1;
	}
	inline pii upd(int s, int t){
		int c = t, minF = INF, len = 0;
		while(c != s){
			len += cost[from[c]][c];
			minF = min(minF, cap[from[c]][c]);
			c = from[c];
		}
		c = t;
		while(c != s){
			cap[from[c]][c] -= minF; 
			cap[c][from[c]] += minF;
			c = from[c];
		}
		return {minF, minF * len};
	}
	inline pii run(int s, int t){
		pii ret = {0, 0}; //flow, cost
		while(SP(s, t)){
			pii x = upd(s, t);
			ret.F += x.F;
			ret.S += x.S;
		}
		return ret;
	}
} flow;

int main(){
	cin >> t;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> s[i] >> take[i];
	}
	flow = Flow();
	fill(frq, frq + 26, 0);
	for(char c : t) frq[c - 'a']++;
	for(int i = 0; i < 26; i++){
		flow.addEdge(N + 2 + i, N + 28, 0, frq[i]);
	}
	for(int i = 0; i < N; i++){
		fill(frq, frq + 26, 0);
		for(char c : s[i]) frq[c - 'a']++;
		for(int j = 0; j < 26; j++){
			flow.addEdge(i + 2, N + 2 + j, 0, frq[j]);
		}
		flow.addEdge(1, i + 2, i + 1, take[i]); 
	}
	pii r = flow.run(1, N + 28);
	//cout << "Flow = " << r.F << ", cost = " << r.S << endl;
	if(r.F != t.length()){
		cout << -1 << endl;
		return 0;
	}
	cout << r.S << endl;
}
