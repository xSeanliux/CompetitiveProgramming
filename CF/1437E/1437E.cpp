#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define all(x) begin(x),end(x)
using namespace std;

const int maxN = 5e5 + 326, INF = 1e9;

class Seg{
	private:
		int seg[maxN * 4];
		void pull(int id){
			seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
		}
	public:
		Seg(){
			fill(seg, seg + maxN * 4, -INF);
		}
		void modify(int id, int l, int r, int p, int v){
			if(l + 1 == r){
				seg[id] = v;
				return;
			}
			int m = (l + r) / 2;
			if(p < m) modify(2 * id + 1, l, m, p, v);
			else modify(2 * id + 2, m, r, p, v);
			pull(id);
		}
		int query(int id, int l, int r, int ql, int qr){
			if(l >= qr || ql >= r) return -INF;
			if(ql <= l && r <= qr) return seg[id];
			int m = (l + r) / 2;
			return max(query(2 * id + 1, l, m, ql, qr), query(2 * id + 2, m, r, ql, qr));
		}
} seg;

int N, M, arr[maxN], stay[maxN], ul[maxN], dl[maxN], dp[maxN], last[maxN];
vector<pii> ord;


int main(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		ord.emplace_back(arr[i] - i, i);
	}
	fill(ul, ul + N + 1, INF);
	fill(dl, dl + N + 1, -INF);
	stay[M + 1] = N + 1;
	stay[0] = 0;
	arr[0] = -INF;
	seg.modify(0, 0, N + 1, 0, 0);
	for(int i = 1; i <= M; i++){
		cin >> stay[i];
		if((arr[stay[i]] - arr[stay[i - 1]]) < (stay[i] - stay[i - 1])){
			cout << -1 << endl;
			return 0;
		}
		for(int j = stay[i], cnt = 0; j > stay[i - 1]; j--, cnt++){
			ul[j] = arr[stay[i]] - cnt;
		}
		seg.modify(0, 0, N + 1, stay[i], 1);
		dp[stay[i]] = 1;
	}
	for(int i = 1; i <= M; i++){
		for(int j = stay[i], cnt = 0; j < stay[i + 1]; j++, cnt++){
			dl[j] = arr[stay[i]] + cnt;
			last[j] = stay[i];
		}
	}
	for(int i = 1; i <= N; i++){
		//cout << "dl[" << i << "] = " << dl[i] << ", ul[" << i << "] = " << ul[i] << endl;
	}
	sort(all(ord));
	for(auto [val, ind] : ord){
		//cout << "ind = " << ind << endl;
		if(dp[ind] || arr[ind] > ul[ind] || arr[ind] < dl[ind]) continue;
		//cout << "dp[" << ind << "] = " << dp[ind] << endl;
		//cout << "last[" << ind << "] = " << last[ind] << endl;
		dp[ind] = seg.query(0, 0, N + 1, last[ind], ind) + 1;
		seg.modify(0, 0, N + 1, ind, dp[ind]);
	}
	int ans = 0;
	for(int i = 1; i <= N; i++){
		//cout << dp[i] << endl;
	}
	for(int i = 1; i < stay[1]; i++){
		ans = max(ans, dp[i]);
	}
	for(int i = 1; i <= M; i++){
		int m = 0;
		for(int j = stay[i] + 1; j < stay[i + 1]; j++){
			m = max(m, dp[j] - 1);
		}
		//cout << i << "th: " << m << endl;
		ans += m;
	}
	//cout << "ans = " << ans << endl;
	//cout << "N = " << N << ", M = " << M << endl;
	cout << (N - ans - M) << endl;
}
