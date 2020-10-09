#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <math.h>
#define int long long int
#define double long double
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

string _dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/109校內初賽/circdraw/", dir;

ifstream infile;
ofstream outfile;


int N;
vector<double> x, y;

inline void solve(string folder, int tc){
	dir = _dir + folder + "/" + to_string(tc); 
	outfile.open(dir + ".out");
	infile.open(dir + ".in");
	infile >> N;
	x.resize(N);
	y.resize(N);
	double ans = 0, xp = 0, yp = 0;
	for(int i = 0; i < N; i++) infile >> x[i] >> y[i];
	for(int i = 0; i < N; i++){
		ans += (N - 1) * (x[i] * x[i] + y[i] * y[i]) - 2 * (x[i] * xp + y[i] * yp);
		xp += x[i];
		yp += y[i];
	}
	outfile << setprecision(10) << (ans / 2 * acos(-1)) << endl;
	infile.close();
	outfile.close();
	cout << "Solved: " << folder << " / " << tc << endl;
}

signed main(){
	ericxiao;
	for(int t = 0; t <= 20; t++) solve("alltest", t);
}

