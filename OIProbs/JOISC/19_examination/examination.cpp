#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 2e5 + 326;
int N, Q, a, b, c, ans[maxN], sz;

vector<int> lisan;
struct Obj{
	int a, b, c, id;
	bool tag, type;
	Obj(){}
	Obj(int a, int b, int c, int id, bool type): a(a), b(b), c(c), id(id), type(type){}
	void runLis(){
		a = upper_bound(lisan.begin(), lisan.begin() + sz, a) - lisan.begin();
		b = upper_bound(lisan.begin(), lisan.begin() + sz, b) - lisan.begin();
		c = upper_bound(lisan.begin(), lisan.begin() + sz, c) - lisan.begin();
	}
};

struct BIT{
	int bit[maxN * 3];
	BIT(){
		fill(bit, bit + maxN * 3, 0);
	}
	void add(int p, int v){
		for(; p < maxN * 3; p += (p & -p)) bit[p] += v;
	}
	int query(int p){
		if(!p) return 0;
		int r = 0;
		for(; p; p -= (p & -p)) r += bit[p];
		return r;
	}
} bit;

void solve(vector<Obj> v){
	if(v.size() == 1) return;
	sort(v.begin(), v.end(), [](Obj x, Obj y){
		return x.a == y.a ? x.type < y.type : x.a > y.a;
	});
	vector<Obj> l, r;
	for(int i = 0; i < v.size(); i++) (i < v.size() / 2 ? l : r).push_back(v[i]);
	solve(l);
	solve(r);
	for(auto &q : l) q.tag = 1;
	for(auto &q : r) q.tag = 0;
	vector<Obj>().swap(v);
	v.reserve(l.size() + r.size());	
	v.insert(v.end(), l.begin(), l.end());
	v.insert(v.end(), r.begin(), r.end());
	sort(v.begin(), v.end(), [](Obj x, Obj y){
		return x.b == y.b ? x.type < y.type : x.b > y.b;
	});
	for(auto q : v){
		if(q.tag == 0 && q.type == 1){ //wants to query
			ans[q.id] += bit.query(sz + 2) - bit.query(q.c - 1);
		} else if(q.tag == 1 && q.type == 0){
			bit.add(q.c, 1);
		}
	}
	for(auto q : v) if(q.tag == 1 && q.type == 0) bit.add(q.c, -1);
}

vector<Obj> vec;
int main(){
	cin >> N >> Q;
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		lisan.push_back(a);
		lisan.push_back(b);
		lisan.push_back(a + b);
		vec.emplace_back(a, b, a + b, -1, 0);
	}
	for(int i = 0; i < Q; i++){
		cin >> a >> b >> c;
		lisan.push_back(a);
		lisan.push_back(b);
		lisan.push_back(c);
		vec.emplace_back(a, b, c, i, 1);
	}
	sort(lisan.begin(), lisan.end());
	sz = unique(lisan.begin(), lisan.end()) - lisan.begin();
	for(auto &o : vec) o.runLis();
	solve(vec);
	for(int i = 0; i < Q; i++) cout << ans[i] << " \n"[i == Q - 1];
}
