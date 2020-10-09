#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#define double long double
#define int long long int
using namespace std;

string _dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/109校內初賽/eatspice/test_", dir;

ifstream infile;
ofstream outfile;

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

inline void solve(int fold, int tc){
	cout << "Solving " << fold << " / " << tc << endl;
	dir = _dir + to_string(fold) + "/" + to_string(tc);
	infile.open(dir + ".in");
	outfile.open(dir + ".out");
	infile >> N >> L;
	for(int i = 0; i < N; i++) infile >> a[i];
	for(int i = 0; i < N; i++) infile >> b[i];
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
	outfile << fixed << setprecision(9) << m << endl;
	outfile.close();
	infile.close();
}

signed main(){
	solve(1, 0);
	for(int i = 1; i <= 8; i++){
		solve(1, i);
	}
	for(int i = 9; i <= 15; i++){
		solve(2, i);
	}
	for(int i = 16; i <= 20; i++){
		solve(3, i);
	}
	for(int i = 21; i <= 30; i++){
		solve(4, i);
	}
}

