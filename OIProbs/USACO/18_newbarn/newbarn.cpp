#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <utility>
#include <fstream>
#define F first
#define S second
#define pii pair<int,int>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define cin infile
#define cout outfile
using namespace std;

const int maxN = 1e5 + 326;
bool rem[maxN];

vector<int> adj[maxN];

int Q, N, u, v, x, sz[maxN], pa[maxN];
pii maxDist[maxN][2];
char c;
bool vis[maxN];
unordered_map<int,pii> dist[maxN];

ifstream infile;
ofstream outfile;

inline void IO(){
	infile.open("newbarn.in");
	outfile.open("newbarn.out");
}

struct Que{
	char c;
	int x;
	Que(){}
	Que(char c, int x): c(c), x(x){}
};

struct Data{
	int from, dep, id;
	Data(){}
	Data(int from, int dep, int id): from(from), dep(dep), id(id){}
};

deque<Data> dq[maxN];
vector<Que> que;

int getSz(int p, int u){
	sz[u] = 1;
	vis[u] = false;
	for(int v : adj[u]) if(v != p && !rem[v]) sz[u] += getSz(u, v);
	return sz[u];
}

void getD(int p, int u, int from, int maxC, int d){
	maxC = max(maxC, u);
	dist[u][from] = dist[from][u] = {d++, maxC};
	//cout << "dist[" << u << "][" << from << "] = " << dist[u][from] << endl;
	for(int v : adj[u]) if(!rem[v] && v != p) getD(u, v, from, maxC, d);
}

int find(int p, int u, int S){
	for(int v : adj[u]) if(v != p && !rem[v]) if(sz[v] * 2 > S) return find(u, v, S);
	return u;
}

void centroid(int p, int u){
	int c = find(u, u, getSz(u, u));
	getD(c, c, c, c, 0);
	pa[c] = p;
	rem[c] = true;
	for(int v : adj[c]) if(!rem[v]) centroid(c, v);
}

int main(){
	IO();
	ericxiao
	cin >> Q;
	while(Q--){
		cin >> c >> x;
		if(c == 'B'){
			N++;
			if(~x){
				adj[N].push_back(x);
				adj[x].push_back(N);
			}
			x = N;
		} 
		que.emplace_back(c, x);
	}
	for(int i = 1; i <= N; i++){
		if(!rem[i]) centroid(-1, i);
	}
	int curT = 0;
	for(auto Q : que){
		if(Q.c == 'B'){
			curT++;
			//cout << "adding " << Q.x << endl;
			int cur = Q.x;
			while(~pa[cur]){ //update 
				//cout << "updating " << pa[cur] << " with " << dist[pa[cur]][Q.x].F << ", " << cur << endl;
				if(maxDist[pa[cur]][0].F <= dist[pa[cur]][Q.x].F){
					if(maxDist[pa[cur]][0].S == cur) maxDist[pa[cur]][0].F = dist[pa[cur]][Q.x].F;
					else {
						maxDist[pa[cur]][1] = {dist[pa[cur]][Q.x].F, cur};
						swap(maxDist[pa[cur]][1], maxDist[pa[cur]][0]);
					}
				} else if(maxDist[pa[cur]][1].F < dist[pa[cur]][Q.x].F && maxDist[pa[cur]][0].S != cur){
					maxDist[pa[cur]][1] = {dist[pa[cur]][Q.x].F, cur};
				}
				cur = pa[cur];
			}
		} if(Q.c == 'Q'){
			int ans = maxDist[Q.x][0].F, cur = Q.x;
			//cout << "ans currently set to " << ans << endl;
			while(~pa[cur]){
				//cout << "now looking at " << pa[cur] << endl;
				if(dist[pa[cur]][Q.x].S <= curT){ 
					int k = dist[pa[cur]][Q.x].F + (cur == maxDist[pa[cur]][0].S ? maxDist[pa[cur]][1].F : maxDist[pa[cur]][0].F);
					ans = max(ans, k);
				}
				cur = pa[cur];
			}
			cout << ans << endl;
		}
	}
}
