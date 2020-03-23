#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxNodes = 5e7, maxN = 5e5;

int bit[maxN], l[maxNodes], r[maxNodes], sum[maxNodes], cnt = 1, arr[maxN];
int N, Q;
vector<int> lisan;

inline int newNode(){
	return cnt++;
}

inline void pull(int id){
	sum[id] = 1 + sum[l[id]] + sum[r[id]];
}

int query(int id, int ql, int qr, int l, int r){
	if(!id) return 0;
	if(ql <= l && qr <= r) return seg[id];
	if(ql >= r || l >= qr) return 0;
	int m = (l + r) / 2;
	return query(l[id], ql, qr, l, m) + query(r[id], ql, qr, m, r); 
}

void modify(int id, int l, int r, int pos){
	if(l + 1 == r){
		sum[id]++;
		return;
	}
	int m = (l + r) / 2;
	if(pos < m){
		if(!l[id]){
			l[id] = newNode();
		}
		modify(l[id], l, m, pos);
	} else{
		if(!r[id]){
			r[id] = newNode();
		}
	}
	pull(id);
}

int Query(int val, int pos){ //how many numbers less than val and behind pos
	int r = 0;
	for(; pos; pos -= (pos & -pos)) r += query(bit[pos], 0, val, 0, N);
	return r;
}

void Modify(int val, int pos){
	for(; pos <= N; pos += (pos & -pos)) modify(bit[pos], 0, N, val);
}

vector<int> countScans(vector<int> A, vector<int> X, vector<int> V){
	N = A.size();
	Q = X.size();
	vector<int> ans;
	for(int i = 1; i <= N; i++) bit[i] = newNode();
	for(int x : A) lisan.push_back(x);
	for(int x : V) lisan.push_back(x);
	sort(lisan.begin(), lisan.end());
	int sz = unique(lisan.begin(), lisan.end()) - lisan.begin();
	for(int &x : A) x = lower_bound(lisan.begin(), lisan.begin() + sz, x) - lisan.begin();
	for(int &x : V) x = lower_bound(lisan.begin(), lisan.begin() + sz, x) - lisan.begin();
	int swaps = 0;	
	for(int i = 0; i <= N; i++){
		swaps += Query(A[i] + 1, i + 1); 
		Modify(A[i], i + 1);
	}
	ans.push_back(swaps);
	for(int i = 0; i < Q; i++){
		swaps -= Query(A[X[i]], V[i]);
	}

}
