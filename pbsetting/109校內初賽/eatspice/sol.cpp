#include <iostream>
#include <vector>
#include <iomanip>
#define double long double
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int maxN = 2e5 + 226;  
double eps = 1e-8;
int N, M, L, ma, la, ra;
double a[maxN], b[maxN];
bool check(double x){
	double mv = 1e18;
	double jizz = a[L - 1] / b[L - 1];
	for(int i = L; i < N; i++) jizz = max(jizz, a[i] / b[i]);

	if(x <= jizz) return true;
	for(int i = L; i < N; i++){
		if(mv > a[i - L] - x * b[i - L]){
			mv = a[i - L] - x * b[i - L];
			ma = i - L + 1;
		}
		if(a[i] - x * b[i] >= mv){
			ra = i;
			la = ma;
			return true;
		}
	}
	return false;
}

signed main(){
	ericxiao;
	cin >> N >> L;
	for(int i = 0; i < N; i++) cin >> a[i];
	for(int i = 0; i < N; i++) cin >> b[i];
	for(int i = 1; i < N; i++){
		a[i] += a[i - 1];
		b[i] += b[i - 1];
	}
	double l = 0, r = 1e6, m;
	while(r - l > eps){
		m = (l + r) / 2;
		(check(m) ? l : r) = m;
	}
	check(m);
	printf("%.10Lf\n", m);
	//cout << fixed << setprecision(4) << m << endl;
}
/*
int main(){
	cout << fixed << setprecision(4);
	double a[200007], b[200005];
	int N, x, m = -1, ma = -1;
	double ans = -1;
	cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	for(int i = 0; i < N; i++){
		cin >> b[i];
		if(ans < a[i] / b[i]){
			ans = a[i] / b[i];
			ma = i;
		}
	}
	cout << a[ma] << "/" << b[ma] << " = " << ans << endl;
	cout << ans << endl;
}
*/
