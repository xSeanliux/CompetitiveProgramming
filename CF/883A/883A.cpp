#include <iostream>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

const int maxN = 1e5 + 326;
int N, a, M, vals[maxN], d;

inline int stp(int x){ //next point that can't be reached
	int A = *upper_bound(vals, vals + M + 2, x + d);
	int B = (x + d) / a  * a + a;
	if(x + d >= N * a) return A;
	return min(A, B);
}

signed main(){
	ericxiao;
	cin >> N >> M >> a >> d;
	for(int i = 0; i < M; i++){
		cin >> vals[i];
	}
	vals[M] = max(N * a, vals[M - 1]);
	vals[M + 1] = 5e18 + 326;
	int ans = 0;
	int cur = min(vals[0], a), cov = (d + a) / a;
	for(int i = 0; i <= M; i++){
		//cout << "i = " << i << endl;
		//cout << "val = " << vals[i] << endl;
		//cout << "cur = " << cur << endl;
		if(vals[i] < cur) continue;
		ans++;
		cur = stp(cur);
		if(vals[i] < cur) continue;
		//cout << "aligned to " << cur << ", N = " << cur / a << endl;
		if(cur <= N * a){
			int numA = max(0LL, min(vals[i] / a, N) - (cur - 1) / a - (vals[i] % a == 0 && vals[i] <= N * a) - 1);
			//cout << "jumping " << numA / cov << " times" << endl; 
			ans += numA / cov;
			cur += (numA / cov) * cov * a; 
			//cout << "now at " << cur << endl;
		}
		while(vals[i] >= cur){
			//cout << "cur = " << cur << endl;
			ans++;
			cur = stp(cur);
		}
		//cout << "ans = " << ans << endl;
	}
	cout << ans << endl;
}
