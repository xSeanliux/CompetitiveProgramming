#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <fstream>
#include <iostream>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e3 + 226, maxC = (1 << 10), INF = 1e18;


string _dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/xor_shortest/test_";

ofstream outfile;
ifstream infile;

int N, M, a, b, x, y, s, t;
struct Dijkstra{
	priority_queue<pii, vector<pii>, greater<pii> > pq;	
	vector<pii> adj[maxN * maxN + maxC];	
	int minDist[maxN * maxN + maxC];
	bool visited[maxN * maxN + maxC];
	void addEdge(int u, int v, int w){
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	void run(int s){
		fill(minDist, minDist + maxN * maxN + maxC, INF);
		fill(visited, visited + maxN * maxN + maxC, 0);
		minDist[s] = 0;
		pq.push({0, s});
		while(pq.size()){
			auto [dist, u] = pq.top();
			pq.pop();
			if(visited[u]){
				continue;	
			}
			visited[u] = true;
			for(auto [v, wei] : adj[u]){
				if(visited[v]) continue;	
				if(minDist[v] > dist + wei){
					minDist[v] = dist + wei;
					pq.push({minDist[v], v});
				}
			}
		}
	}
	void reset(){
		for(int i = 1; i <= N * maxN + maxC; i++) vector<pii>().swap(adj[i]);
	}
} sssp;




void gogogo(int subtask, int testcase){
	string indir = _dir + to_string(subtask) + "/" + to_string(testcase) + ".in";
	string outdir = _dir + to_string(subtask) + "/" + to_string(testcase) + ".out";
	infile.open(indir);
	outfile.open(outdir);
	infile >> N >> M >> s >> t;
	for(int i = 0; i < M; i++){
		infile >> a >> b >> x >> y;	
		for(int v = 0; v < maxC; v++){
			sssp.addEdge(maxN * a + v, maxN * b + (v ^ x), y);
		}
	}
	sssp.run(maxN * s);
	outfile << (sssp.minDist[maxN * t] == INF ? -1 : sssp.minDist[maxN * t]) << endl;
	infile.close();
	outfile.close();
	sssp.reset();
}

signed main(){
	for(int subtask = 3; subtask <= 3; subtask++){
		for(int testcase = (subtask - 1) * 10 + 1; testcase <= subtask * 10; testcase++){
			gogogo(subtask, testcase);
			cout << "Solved: " << subtask << " - " << testcase << endl; 
		}
	}
}

