#include <iostream>
#include <cassert>
#include <fstream>
#define cin infile
#define cout outfile
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 326;

int N, x[maxN], y[maxN], cnt[maxN][maxN], ans[maxN], bel[maxN];

ifstream infile;
ofstream outfile;

inline void IO(){
	infile.open("triangles.in");
	outfile.open("triangles.out");
	ericxiao;
}

int Abs(int x){
	return x < 0 ? -x : x;
}

inline int cross(int i, int j, int k){ //(ij x ik)
	return (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]);
}

signed main(){	
	IO();
	cin >> N;
	for(int i = 0; i < N; i++) cin >> x[i] >> y[i];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N - 1; j++){
			if((x[j] > x[j + 1]) || (x[j] == x[j + 1] && y[j] < y[j + 1])){
				swap(x[j], x[j + 1]);
				swap(y[j], y[j + 1]);
			}
		}
	}
	//for(int i = 0; i < N; i++) cout << "P(" << i << ") = " << x[i] << ", " << y[i] << endl;
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			for(int k = 0; k < N; k++){
				if(!(x[i] <= x[k] && x[k] <= x[j])) continue;
				if(x[i] == x[j]){
					cnt[i][j] += (min(y[i], y[j]) >= y[k]); 
				} else {
					//(y - y[i]) = (y[j] - y[i]) / (x[j] - x[i]) * (x - x[i])
					//y = (y[j] - y[i]) / (x[j] - x[i]) * (x - x[i]) + y[i] >= y[k]
					//1 * 3 < 3 * 3
					if(((y[k] * (x[j] - x[i])) < ((y[j] - y[i]) * (x[k] - x[i]) + y[i] * (x[j] - x[i])))){
						cnt[i][j]++;
						//cout << "k = " << k << endl;
					}
				}
			}
			//cout << "cnt " << i << ", " << j << " = " << cnt[i][j] << endl;
			//cout << "dx = " << x[j] - x[i] << endl;
			cnt[j][i] = cnt[i][j];
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(y[j] < y[i] && x[i] == x[j]) bel[i]++;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			for(int k = j + 1; k < N; k++){	
				int d;
				//cout << "i = " << i << ", j = " << j << ", k = " << k << endl;
				if(x[i] == x[j]){
					d = cnt[i][k] - cnt[j][k] - 1;
					//cout << "d = " << d << endl;
				} else if(x[j] == x[k]){
					d = cnt[i][j] - cnt[i][k] - 1;
				} else {
					if(cross(k, i, j) <= 0){
						d = cnt[i][j] + cnt[j][k] - cnt[i][k] - bel[j];	
					} else {
						d = cnt[i][k] - cnt[i][j] - cnt[j][k] + bel[j] - 1;
					}
				}
				//cout << "d = " << d << endl;
				ans[d]++;
			}
		}
	}
	for(int i = 0; i <= N - 3; i++){
		cout << ans[i] << endl; 
	}
}
