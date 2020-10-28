#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

const int maxN = 2e5 + 326;
int N, K, bit[maxN];
vector<int> vals, lisan;

void modify(int p, int x){
	for(; p < maxN; p += p & -p) bit[p] += x;
}

int query(int p){
	if(!p) return 0;
	int r = 0;
	for(; p; p -= p & -p) r += bit[p];
	return r;
}

signed main(){
	cin >> N >> K;
	vals.resize(N + 1);
	for(int i = 1; i <= N; i++) cin >> vals[i];
	for(int i = 1; i <= N; i++) vals[i] += vals[i - 1]; 
	for(int i = 1; i <= N; i++) vals[i] -= i * K;
	for(int x : vals) lisan.push_back(x);
	sort(lisan.begin(), lisan.end());
	int sz = unique(lisan.begin(), lisan.end()) - lisan.begin();
	for(int &x : vals){
		x = lower_bound(lisan.begin(), lisan.begin() + sz, x) - lisan.begin() + 1;
	}
	int ans = 0;
	for(int i = 0; i <= N; i++){
		ans += query(vals[i]);
		modify(vals[i], 1);
	}
	cout << ans << endl;
}


