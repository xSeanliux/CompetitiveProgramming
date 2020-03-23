#include <iostream>
#include <algorithm>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 2e5 + 10, MOD = 998244353;
int N, K, pos[maxN], x;

signed main(){
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> x;
		pos[x] = i;
	}
	vector<int> poss;
	int s = 0;
	for(int i = 0; i < K; i++){
		s += (N - i);
		poss.push_back(pos[N - i]);
	}
	sort(poss.begin(), poss.end());
	int ans = 1;
	for(int i = 1; i < poss.size(); i++){
		ans = ans * (poss[i] - poss[i - 1])	% MOD;
	}
	cout << s << " " << ans << endl;
}
