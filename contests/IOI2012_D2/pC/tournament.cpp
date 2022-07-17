#include <iostream>
#include <deque>
#include <cassert>
#include <vector>
using namespace std;

const int maxN = 1e5 + 326, maxLog = 17;

vector<int> adj[maxN];
int indeg[maxN], firstOp[maxN], anc[maxLog][maxN], lat[maxN], rat[maxN], dep[maxN];

struct Treap{
	inline static int Rand(){
		static int seed = 31;
		return seed = (seed * 3 + 1) % 0xdefaced;
	}
	struct Node{
		int pri, L, R, sz, lastque;
		Node *l, *r;
		Node(int p = 0): pri(Rand()), L(p), R(p), sz(1), l(NULL), r(NULL), lastque(-1){}
	} *root = NULL;
	inline int Sz(Node *n){
		return n ? n->sz : 0;
	}
	inline void pull(Node *&n){
		n->sz = Sz(n->l) + Sz(n->r) + 1;
	}
	void Split(Node *o, Node *&a, Node *&b, int k){ //a has k objs
		if(!o){
			a = b = o;
			return;
		}
		if(Sz(o->l) + 1 <= k){
			a = o;
			k -= Sz(o->l) + 1;
			Split(o->r, a->r, b, k);
			pull(a);
		} else {
			b = o;
			Split(o->l, a, b->l, k);
			pull(b);
		}
		pull(o);
	}
	Node* Merge(Node *a, Node *b){
		if(!a || !b) return a ? a : b;
		if(a->pri < b->pri){
			a->r = Merge(a->r, b);
			pull(a);
			return a;
		}
		b->l = Merge(a, b->l);
		pull(b);
		return b;
	}
	void Append(int pos){ //push back
		root = Merge(root, new Node(pos));
	}
	void dfs(Node *n, Node *&ori, int id){
		if(!n) return;
		if(~n->lastque){
			adj[id].push_back(n->lastque);
			indeg[n->lastque]++;
		} else {
			assert(n->L == n->R);
			firstOp[n->L] = id;
		}
		ori->L = min(ori->L, n->L);
		ori->R = max(ori->R, n->R);
		dfs(n->l, ori, id);
		dfs(n->r, ori, id);
	}
	void newQue(int &l, int &r, int queid){
		Node *a, *b, *c, *d;
		Split(root, a, b, l);
		Split(b, c, d, r - l + 1); //c is what we actually want
		Node *n = new Node();
		n->L = maxN;
		n->R = -1;
		n->lastque = queid;
		dfs(c, n, queid);
		lat[queid] = n->L;
		rat[queid] = n->R;
		root = Merge(a, Merge(n, d));
	}
} treap;

struct RMQ{
	int arr[maxLog][maxN], *bas, N;
	RMQ(int N = 0, int *bas = NULL): N(N), bas(bas){}
	void build(){
		//cout << "building " << endl;
		for(int i = 0; i < N; i++){
			arr[0][i] = bas[i];
		}
		for(int i = 1; (1 << i) <= N; i++){
			for(int j = 0; j + (1 << i) - 1 < N; j++){
				arr[i][j] = max(arr[i - 1][j], arr[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	inline int query(int l, int r){
		int k = 0;
		while((1 << (k + 1)) < (r - l + 1)) k++;
		//cout << "trying to get " << l << " to " << r << endl;
		//cout << "k = " << k << endl;
		assert((1 << (k + 1)) >= (r - l + 1) && (1 << k) <= (r - l + 1));
		return max(arr[k][l], arr[k][r - (1 << k) + 1]);
	}
} rmq;

void getAnc(int p, int u){
	//cout << "Running getAnc(" << p << ", " << u << ")" << endl;
	anc[0][u] = p;
	dep[u] = dep[p] + 1;
	for(int i = 1; i < maxLog; i++) anc[i][u] = anc[i - 1][anc[i - 1][u]];
	for(int x : adj[u]) getAnc(u, x);
}

int GetBestPosition(int N, int C, int R, int *K, int *S, int *E) {
	rmq = RMQ(N - 1, K);
	rmq.build();
	//cout << "Fin RMQ" << endl;
	for(int i = 0; i < N; i++){
		treap.Append(i);	
	}
	//cout << "Fin treap" << endl;
	for(int i = 0; i < C; i++){
		treap.newQue(S[i], E[i], i);
	}
	for(int i = 0; i < C; i++){
		if(!indeg[i]){
			getAnc(i, i);
		}
	}
	for(int i = 0; i < C; i++){
		//cout << "For the " << i << "th option: " << endl;
		//cout << lat[i] << ", " << rat[i] << endl;
	}
	int mx = -1, maxAt = 0;
	for(int pos = 0; pos < N; pos++){
		int cur = firstOp[pos], jump = 0;
		for(int d = maxLog - 1; d >= 0; d--){
			int qid = anc[d][cur], oth = rmq.query(lat[qid], rat[qid] - 1);
			assert(lat[qid] <= pos && pos <= rat[qid]);
			if(oth < R){
				cur = anc[d][cur];
			}
		}
		int qid = firstOp[pos], oth = rmq.query(lat[qid], rat[qid] - 1);
		if(oth < R) jump = dep[qid] - dep[cur] + 1;
		else jump = 0;
		
		if(jump > mx){
			mx = jump;
			maxAt = pos;
		}
	}
	return maxAt;
}
