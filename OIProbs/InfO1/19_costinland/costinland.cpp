#include <iostream>
#define int long long int
using namespace std;

int D;
const int maxN = 63;
char mp[maxN][maxN];

inline void solve(int D){
	for(int i = 0; i < maxN; i++){
		for(int j = 0; j < maxN; j++) mp[i][j] = '.';
	}
	for(int i = 0; i < maxN - 1; i++){
		mp[i][maxN - 1] = 'd';
		mp[maxN - 1][i] = 'r';
	}
	for(int i = 0; i < maxN - 1; i++){
		mp[i][i] = 'X';
		mp[i][i + 1] = 'd';
		mp[i + 1][i] = 'r';
	}

	for(int i = 0; i < maxN; i++){
		if((D >> i) & 1){
			if((D >> (i + 1)) == 0){
				for(int j = i; j < maxN - 1; j++){
					mp[j][j] = mp[j][j + 1] = mp[j + 1][j] = '.';
				}
			} else mp[i][i + 1] = 'X';
		}
	}
	for(int i = 0; i < maxN - 1; i++){
		mp[i][maxN - 1] = 'd';
		mp[maxN - 1][i] = 'r';
	}

	cout << maxN << " " << maxN << endl;
	for(int i = 0; i < maxN; i++){
		for(int j = 0; j < maxN; j++){
			cout << mp[i][j];
		}
		cout << endl;
	}
}

signed main(){
	cin >> D;
	solve(D);
}
