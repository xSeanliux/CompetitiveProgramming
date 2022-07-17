#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>
#define ld long double
using namespace std;

const int maxN = 2e5 + 326;
int N, T, x, y;
vector<ld> A, B;

inline void solve(){
	cin >> N;
	vector<ld>().swap(A);
	vector<ld>().swap(B);
	for(int i = 0; i < 2 * N; i++){
		cin >> x >> y;
		x = abs(x);
		y = abs(y);
		(x == 0 ? B : A).push_back((x == 0 ? y : x));
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	ld ans = 0;
	for(int i = 0; i < N; i++) ans += hypot(A[i], B[i]);
	cout << setprecision(10) << ans << endl;
}
int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
