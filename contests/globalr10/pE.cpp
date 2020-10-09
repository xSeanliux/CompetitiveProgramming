#include <iostream>
#define int long long int
using namespace std;

const int maxN = 30;
int N, q, k, grid[maxN][maxN];

signed main(){
	cin >> N;
	int cur = 1;
	for(int i = 0; i < N; i += 2){
		for(int j = 0; j < N; j++){
			grid[i][j] = (1LL << (i + j));	
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cin >> q;
	while(q--){
		cin >> k;
		int i = 0, j = 0;
		while(i < N - 1 || j < N -1){
			cout << i + 1 << " " << j + 1 << endl;
			if(i == N - 1){
				for(j++; j < N; j++){
					cout << i + 1 << " " << j + 1 << endl;

				}
				break;
			}
			if(j == N - 1){
				for(i++; i < N; i++){
					cout << i + 1 << " " << j + 1 << endl;
				}
				break;
			}
			if((k >> (i + j + 1)) & 1){
				if(grid[i + 1][j]){
					i++;
				} else j++;
			} else {
				if(grid[i + 1][j]){
					j++;
				} else {
					i++;
				}
			}
		}
	}
}
