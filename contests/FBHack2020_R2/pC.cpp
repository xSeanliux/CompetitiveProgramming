#include <iostream>
#include <vector>
#include <map>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 326, MOD = 1e9 + 7;
int ed[maxN], sum[maxN][2], T, N, M, E, K, A, B, C, D, X[maxN], Y[maxN], I[maxN], W[maxN], ans, mst, c;
map<int, int> ring[maxN][2];

inline int add(int a, int b, int m){
	return (a % m + b % m + m) % m;
}
inline void solve(){
	ans = 1;
	mst = 0;
	cin >> N >> M >> E >> K;
	for(int i = 0; i < K; i++) cin >> X[i];
	cin >> A >> B >> C;
	for(int i = K; i < N; i++) X[i] = (A * X[i - 2] + B * X[i - 1] + C) % M;
	for(int i = 0; i < K; i++) cin >> Y[i];
	cin >> A >> B >> C;
	for(int i = K; i < N; i++) Y[i] = (A * Y[i - 2] + B * Y[i - 1] + C) % M;
	for(int i = 0; i < N; i++) if(X[i] > Y[i]) swap(X[i], Y[i]);

	for(int i = 0; i < K; i++) cin >> I[i];
	cin >> A >> B >> C;
	for(int i = K; i < E; i++) I[i] = (A * I[i - 2] + B * I[i - 1] + C) % (N * M + N);
	for(int i = 0; i < K; i++) cin >> W[i];
	cin >> A >> B >> C;
	for(int i = K; i < E; i++) W[i] = (A * W[i - 2] + B * W[i - 1] + C) % (int)(1e9);
	
	for(int i = 0; i < N; i++){
		ring[i][0] = ring[i][1] = map<int, int>();
		sum[i][0] = ring[i][0][1] = Y[i] - X[i];
		sum[i][1] = ring[i][1][1] = M - (Y[i] - X[i]);
	}
	for(int i = 0; i < N * M + N; i++){
		ed[i] = 1;
	}
	mst = N * M - 1;
	for(int i = 0; i < E; i++){
		if(I[i] >= N * M){
			mst = add(mst, -ed[I[i]], MOD);
			ed[I[i]] = W[i];
			mst = add(mst, ed[I[i]], MOD);
			ans = ans * mst % MOD;
			continue;
		}
		int blk = I[i] / M;
		if(X[i] <= I[i] % M && I[i] % M < Y[i]){
			mst = add(mst, -(sum[blk][0] - ring[blk][0].rbegin()->F), MOD);
			sum[blk][0] -= ed[I[i]];
			ring[blk][0][ed[I[i]]]--;
			if(!ring[blk][0][ed[I[i]]]) ring[blk][0].erase(ed[I[i]]);
			ed[I[i]] = W[i];

			sum[blk][0] += W[i];
			ring[blk][0][W[i]]++;
			mst = add(mst, (sum[blk][0] - ring[blk][0].rbegin()->F), MOD);
		} else {
			mst = add(mst, -(sum[blk][1] - ring[blk][1].rbegin()->F), MOD);
			sum[blk][1] -= ed[I[i]];
			ring[blk][1][ed[I[i]]]--;
			if(!ring[blk][1][ed[I[i]]]) ring[blk][1].erase(ed[I[i]]);
			ed[I[i]] = W[i];

			sum[blk][1] += W[i];
			ring[blk][1][W[i]]++;
			mst = add(mst, (sum[blk][1] - ring[blk][1].rbegin()->F), MOD);

		}
		ans = ans * mst % MOD;
	}
	cout << "Case #" << ++c << ": " << ans << '\n';

}

signed main(){
	ericxiao;
	cin >> T;
	while(T--){
		solve();
	}
}
