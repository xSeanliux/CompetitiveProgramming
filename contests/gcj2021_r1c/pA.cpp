#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int c = 0;

inline int f(int n){
	if(n <= 0) return 0;
	return (n - 1) / 2 + 1;	
}
inline void solve(){
	int N, K;
	vector<int> p = vector<int>(), lens = vector<int>();
	cin >> N >> K;
	p.resize(N);
	for(int i = 0; i < N; i++) cin >> p[i];
	sort(p.begin(), p.end());
	int st = p[0] - 1, ed = K - p[N - 1];
	int ans = st + ed;
	for(int i = 1; i < N; i++){
		lens.push_back(f(p[i] - p[i - 1] - 1));
		ans = max(ans, p[i] - p[i - 1] - 1);
	}
	sort(lens.begin(), lens.end(), greater<int>());
	//cout << "st = " << st << ", ed = " << ed << endl;
	if(lens.size()){
		ans = max(ans, max(st, ed) + lens[0]);
	}
	if(lens.size() > 1) ans = max(ans, lens[0] + lens[1]);
	cout << "Case #" << ++c << ": " << ans * 1.0 / K << endl;
}

int main(){
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
