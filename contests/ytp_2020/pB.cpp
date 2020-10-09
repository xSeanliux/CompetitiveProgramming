#include <iostream>
using namespace std;

const int maxN = 1024 + 10;

int N, M, map[maxN][maxN], ans[maxN][maxN];

int main(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) cin >> map[i][j];
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			for(int x = i - 1; x <= i + 1; x++){
				for(int y = j - 1; y <= j + 1; y++){
					ans[i][j] += map[x][y];
				}
			}
			ans[i][j] -= map[i][j];
			cout << ans[i][j] << " \n"[j == M];
		}
	}
}
