#include <iostream>
#include <map>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n, t, pv[maxN], nxt[maxN], vs[3];

struct Tri{
	int verts[3];
	Tri(){}
	Tri(int a, int b, int c){
		verts[0] = a;
		verts[1] = b;
		verts[2] = c;
	}
	pii getEdge(int x){
		vector<int> res;
		for(int i = 0; i < 3; i++){
			if(verts[i] != x) res.push_back(verts[i]);
		}
		return {res[0], res[1]};
	}
};

vector<Tri> tris;
map<pii, vector<pii> > mp;

int main(){
	ericxiao;
	cin >> t;
	while(t--){
		cin >> n;
		tris.clear();
		mp = map<pii, vector<pii> >();
		for(int i = 0; i < n - 2; i++){
			cin >> vs[0] >> vs[1] >> vs[2];
			sort(vs, vs + 3);
			tris.emplace_back(vs[0], vs[1], vs[2]);
			mp[{vs[0], vs[1]}].emplace_back(i, vs[2]);
			mp[{vs[0], vs[2]}].emplace_back(i, vs[1]);
			mp[{vs[1], vs[2]}].emplace_back(i, vs[0]);
		}
		iota(pv, pv + n, 0);
		iota(nxt, nxt + n, 0);
		nxt[tris[0].verts[2]] = pv[tris[0].verts[1]] = tris[0].verts[0];
		nxt[tris[0].verts[0]] = pv[tris[0].verts[2]] = tris[0].verts[1];
		nxt[tris[0].verts[1]] = pv[tris[0].verts[0]] = tris[0].verts[2];
		queue<pii> que;
		vector<int> ord;
		ord.push_back(0);
		for(int i = 0; i < 3; i++) que.push({0, tris[0].verts[i]});
		pii tp, edge;
		Tri triangle;
		while(que.size()){
			tp = que.front();
			//cout << "triangle id = " << tp.F << ", vert = " << tp.S << endl;
			que.pop();
			triangle = tris[tp.F];
			edge = triangle.getEdge(tp.S);
			//cout << "Edge: " << edge.F << ", " << edge.S << endl;
			for(auto p : mp[{edge.F, edge.S}]){
                //cout << "Looking at triangle id = " << p.F << ", vert = " << p.S << endl;
				if(p.F == tp.F) continue;
				//cout << "Connecting " << endl;
				int tri_id = p.F, otherV = p.S;
				if(nxt[edge.F] == edge.S){
					nxt[edge.F] = pv[edge.S] = otherV;
					pv[otherV] = edge.F;
					nxt[otherV] = edge.S;
				} else {
					nxt[edge.S] = pv[edge.F] = otherV;
					nxt[otherV] = edge.F;
					pv[otherV] = edge.S;
				}
				que.push({tri_id, edge.F});
				que.push({tri_id, edge.S});
				ord.push_back(tri_id);
			}
		}
		int current = 1;
		do{
			cout << current << " ";
			current = nxt[current];
		} while(current != 1);
		cout << endl;
		reverse(ord.begin(), ord.end());
        for(int x : ord) cout << x + 1<< " ";
		cout << endl;
	}
}
