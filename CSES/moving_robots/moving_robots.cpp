#include <iostream>
#include <iomanip>
#define double long double
using namespace std;

const int N = 8;
int K, deg[N][N];
double p[N][N], np[N][N];

inline void init(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			deg[i][j] = 4 - (i == 0 || i == 7) - (j == 0 || j == 7);
			p[i][j] = 1;
		}
	}
}

inline void step(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			np[i][j] = 0;
			if(i) np[i][j] += p[i - 1][j] * (1) / (deg[i - 1][j]);	
			if(j) np[i][j] += p[i][j - 1] * (1) / (deg[i][j - 1]);	
			if(i < N - 1) np[i][j] += p[i + 1][j] * (1) / (deg[i + 1][j]);	
			if(j < N - 1) np[i][j] += p[i][j + 1] * (1) / (deg[i][j + 1]);	
		}
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) p[i][j] = np[i][j];
}

inline double Abs(double x){
	return x < 0 ? -x : x;
}

int main(){
	init();
	cin >> K;
	for(int i = 0; i < K; i++){
		step();
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				cout << p[j][k] << " \n"[k == N - 1];
			}
		}
		cout << "--------------\n";
	}
	//calc
	double exp = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) exp += Abs(1 - p[i][j]);
	cout << setprecision(10) << exp << endl;
}
