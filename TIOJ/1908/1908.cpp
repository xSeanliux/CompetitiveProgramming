#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxN = 25, NINF = -1;

int dp[maxN][maxN][(1 << maxN)], N, vals[maxN][maxN];

bool isValid[maxN][(1 << maxN)];

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> vals[i][j];
		}
	}

}

