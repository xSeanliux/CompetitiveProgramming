#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <math.h>
#define pii pair<int,int>
#define pid pair<int,double>
#define pdi pair<double, int>
#define F first
#define S second
#define int long long int 
using namespace std;

const int maxN = 226;
const double eps = 1e-9;
int N, M, q, a, b, c, d;

int hori[maxN], vert[maxN];
double obs[maxN];
vector<pii> points, ques;
vector<pid> adj[maxN * maxN];
vector<int> lishor, lisvert;

inline int getHash(int a, int b){
	return a * maxN + b;
}

inline int Abs(int x){
	return x < 0 ? -x : x;
}

inline double Abs(double x){
	return x < eps ? -x : x;
}

inline bool cmp(double a, double b){
	return a + eps < b;	
}

priority_queue<pdi, vector<pdi>, greater<pdi> > pq;
double minDist[maxN * maxN];
bool visited[maxN * maxN];

inline void Dijkstra(int st){
	fill(minDist, minDist + maxN * maxN, 1e12);
	fill(visited, visited + maxN * maxN, false);
	minDist[st] = 0;
	pq.push({0, st});
	while(pq.size()){
		pdi p = pq.top();
		pq.pop();
		if(visited[p.S]) continue;
		visited[p.S] = true;
		for(auto e : adj[p.S]){
			if(visited[e.F]) continue;
			if(minDist[e.F] > p.F + e.S){
				minDist[e.F] = p.F + e.S;
				pq.push({minDist[e.F], e.F});
			}
		}
	}
}

signed main(){
	cin >> N >> M;	
	for(int i = 0; i < N; i++){
		cin >> hori[2 * i] >> hori[2 * i + 1];
		hori[2 * i] += 1e5;
		hori[2 * i + 1] += 1e5;
		obs[2 * i] = hori[2 * i];
		obs[2 * i + 1] = hori[2 * i + 1];
		lishor.push_back(hori[2 * i]);
		lishor.push_back(hori[2 * i + 1]);
	}
	for(int i = 0; i < M; i++){
		cin >> vert[2 * i] >> vert[2 * i + 1];
		vert[2 * i] += 1e5;
		vert[2 * i + 1] += 1e5;
		lisvert.push_back(vert[2 * i]);
		lisvert.push_back(vert[2 * i + 1]);
	}
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> a >> b >> c >> d;
		a += 1e5;
		b += 1e5;
		c += 1e5;
		d += 1e5;
		ques.emplace_back(a, b);
		ques.emplace_back(c, d);
		lishor.push_back(b);
		lishor.push_back(d);
		lisvert.push_back(a);
		lisvert.push_back(c);
		points.emplace_back(a, b);
		points.emplace_back(c, d);
	}
	sort(lishor.begin(), lishor.end());
	sort(lisvert.begin(), lisvert.end());
	int horsz = unique(lishor.begin(), lishor.end()) - lishor.begin();
	int vertsz = unique(lisvert.begin(), lisvert.end()) - lisvert.begin();
	for(int i = 0; i < horsz; i++){
		for(int j = 0; j < vertsz; j++){
			for(int k = 0; k < horsz; k++){
				for(int l = j; l < vertsz; l++){
					cout << "From (" << lisvert[j] << ", " << lishor[i] << ") to (" << lisvert[l] << ", " << lishor[k] << ")" << endl;
					//from (lisvert[j], lishor[i]) <-> (lisvert[l], lishor[k])
					if(i == k && j == l){
						continue;
					}
					if(i == k || j == l){
						adj[getHash(l, k)].emplace_back(getHash(j, i), Abs(lisvert[l] - lisvert[j]) + Abs(lishor[k] - lishor[i]));
						adj[getHash(j, i)].emplace_back(getHash(l, k), Abs(lisvert[l] - lisvert[j]) + Abs(lishor[k] - lishor[i]));
						cout << "YES: " << Abs(lisvert[l] - lisvert[j]) + Abs(lishor[k] - lishor[i]) << endl;
						continue;
					}
					bool can = true;
					for(int x = j; x <= l; x++){
						//y = lishor[i] + (lishor[k] - lishor[i]) / (lisvert[l] - lisvert[j]) * (lisvert[x] - lisvert[j])		
						if(((lishor[k] - lishor[i]) * (lisvert[x] - lisvert[j])) % (lisvert[l] - lisvert[j]) == 0){
							continue;
						}
						double y = lishor[i] + (lishor[k] - lishor[i]) / (lisvert[l] - lisvert[j]) * (lisvert[x] - lisvert[j]);										  int rk = lower_bound(obs, obs + 2 * N, y, cmp) - obs; //this is gonna get me TLE
						if(rk % 2 == 0){
							can = false;
							break;
						}
					}
					if(can){
						double h = hypot(lisvert[l] - lisvert[j], lishor[k] - lishor[i]);
						cout << "YES: " << h << endl;
						adj[getHash(l, k)].emplace_back(getHash(j, i), h);
						adj[getHash(j, i)].emplace_back(getHash(l, k), h);		
					}
				}
			}
		}
	}
	for(int i = 0; i < q; i++){
		pii st = ques[2 * i], en = ques[2 * i + 1];
		int a = lower_bound(lisvert.begin(), lisvert.begin() + vertsz, st.F) - lisvert.begin();
		int b = lower_bound(lishor.begin(), lishor.begin() + horsz, st.S) - lishor.begin();
		int c = lower_bound(lisvert.begin(), lisvert.begin() + vertsz, en.F) - lisvert.begin();
		int d = lower_bound(lishor.begin(), lishor.begin() + horsz, en.S) - lishor.begin();
		Dijkstra(getHash(a, b));
		cout << minDist[getHash(c, d)] << endl;
	}
}
