#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 2e5 + 326;

struct Seg{
	int seg[maxN << 2], tag[maxN << 2];
	inline void pull(int id){
		seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
	}
	inline void push(int id, int l, int r){
		if(!tag[id]) return;
		seg[id] += tag[id] * (r - l);
		if(r - l > 1){
			tag[2 * id + 1] += tag[id];
			tag[2 * id + 2] += tag[id];
		}
		tag[id] = 0;
	}
	void modify(int id, int l, int r, int ql, int qr, int v){
		push(id, l, r);
		if(l >= qr || ql >= r) return;	
		if(ql <= l && r <= qr){
			tag[id] += v;
			push(id, l, r);
			return;
		}
		int m = (l + r) / 2;
		modify(2 * id + 1, l, m, ql, qr, v);
		modify(2 * id + 2, m, r, ql, qr, v);
		pull(id);
	}
	int query(int id, int l, int r, int ql, int qr){
		push(id, l, r);
		if(l >= qr || ql >= r) return 0;
		if(ql <= l && r <= qr) return seg[id];
		int m = (l + r) / 2;
		return query(2 * id + 1, l, m, ql, qr) + query(2 * id + 2, m, r, ql, qr);
	}
} seg;

int N, M, a, b, arr[maxN], ans[maxN];
vector<pii> ques[maxN];
stack<pii> stk;

signed main(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> arr[i];
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		ques[a].emplace_back(b, i);
	}
	for(int i = N; i; i--){
		//cout << "i = " << i << endl;
		int cur = i;
		while(stk.size() && stk.top().F <= arr[i]){
			seg.modify(0, 1, N + 1, cur + 1, stk.top().S + 1, arr[i] - stk.top().F);
			//cout << "l = " << i + 1 << ", r = " << stk.top().S + 1 << ", val = " << arr[i] - stk.top().F << endl;
			cur = stk.top().S;
			stk.pop();
		}
		stk.push({arr[i], cur});
		for(auto [r, id] : ques[i]){
			ans[id] = seg.query(0, 1, N + 1, i, r + 1);
		}
	}
	for(int i = 0; i < M; i++) cout << ans[i] << " \n"[i == M - 1];
}
