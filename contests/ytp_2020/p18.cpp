#include <iostream>
#pragma optimize gcc ("O3")
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2e5 + 10;

struct RMQ{
	signed seg[maxN * 4 + 10];
	void init(){
		fill(seg, seg + maxN * 4 + 10, maxN);
	}
	inline void pull(int id){
		seg[id] = min(seg[2 * id + 1], seg[2 * id + 2]);
	}
	void modify(int id, int pos, int l, int r, int val){
		if(l + 1 == r){
			seg[id] = val;
			return;
		}
		int m = (l + r) / 2;
		if(pos < m){
			modify(2 * id + 1, pos, l, m, val);
		} else {
			modify(2 * id + 2, pos, m, r, val);
		}
		pull(id);
	}
	int query(int id, int l, int r, int ql, int qr){
		//cout << "Running que(" << id << ", " << l << ", " << r << ", " << ql << ", " << qr << endl;
		if(l >= qr || ql >= r) return maxN;
		if(ql <= l && r <= qr) return seg[id];
		int m = (l + r) / 2;
		return min(query(2 * id + 1, l, m, ql, qr), query(2 * id + 2, m, r, ql, qr));
	}
} rmq;

struct BIT{
	int arr[maxN];
	BIT(){
		fill(arr, arr + maxN, 0);
	}
	void add(int p, int x){
		for(; p < maxN; p += (p & -p)){
			arr[p] += x;
		}
	}
	int sum(int p){
		if(p <= 0) return 0;
		int r = 0;
		for(; p; p -= (p & -p)) r += arr[p];
		return r;
	}
} bit, numbit;

int N, Q, K, que, val[maxN], sum[maxN], nxt[maxN], last[maxN], num[maxN], allsum, allnum;

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	rmq = RMQ();
	rmq.init();
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> val[i];
		val[i]++;
	}
	for(int i = N - 1; i >= 0; i--){
		int nxt = rmq.query(0, 0, maxN, max(0LL, val[i] - K), min(maxN, val[i] + K + 1));
		//cout << "nxt[" << i << "] = " << nxt << endl;
		sum[i] = val[i];
		num[i] = 1;
		if(nxt < N){
			sum[i] += sum[nxt]; 
			num[i] += num[nxt];
			last[i] = last[nxt];
		} else {
			last[i] = val[i];
		}
		bit.add(last[i], sum[i]);
		numbit.add(last[i], num[i]);
		rmq.modify(0, val[i], 0, maxN, i);
		allsum += sum[i];
		allnum += num[i];
	}
	//cout << "ASUM = " << allsum << endl;
	//cout << "DDDD" << endl;
	cin >> Q;
	while(Q--){
		cin >> que;
		if(que >= maxN){
			cout << 0 << endl;
			continue;
		}
		//cout << "bitsum = " << bit.sum(que - 1) << endl;
		//cout << "numsum = " << numbit.sum(que - 1) << endl;
		cout << (allsum - bit.sum(que)) - (allnum - numbit.sum(que)) << endl;
	}
}

