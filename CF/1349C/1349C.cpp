#include <iostream>
#include <queue>
#include <string> 
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 1e3 + 226, INF = 2e18;
int T, N, M, arr[maxN][maxN], x, y, t, _x, _y, p, Q, minT[maxN][maxN];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, curCol;
string s;
queue<int> que;

int hsh(int y, int x){
	return y * maxN + x;
}

signed main(){
	cin >> N >> M >> Q;
	for(int i = 0; i <= N + 1; i++) for(int j = 0; j <= M + 1; j++){
		arr[i][j] = 2;
		minT[i][j] = INF;
	}
	for(int i = 1; i <= N; i++){
		cin >> s;
		for(int j = 1; j <= M; j++){
			arr[i][j] = s[j - 1] == '1';
		}
	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			for(int d = 0; d < 4; d++){
				_x = j + dx[d];
				_y = i + dy[d];
				if(_x < 1 || _y < 1 || _x > M || _y > N) continue;
				if(arr[i][j] == arr[_y][_x]){
					minT[i][j] = 0;
					que.push(hsh(i, j));
				}
			}
		}
	}

	while(que.size()){
		int p = que.front();
		que.pop();
		y = p / maxN;
		x = p % maxN;
		for(int d = 0; d < 4; d++){
			_x = x + dx[d];
			_y = y + dy[d];
			if(_x < 1 || _y < 1 || _x > M || _y > N) continue;
			if((arr[y][x] != arr[_y][_x]) && (minT[_y][_x] > minT[y][x] + 1)){
				minT[_y][_x] = minT[y][x] + 1;
				que.push(hsh(_y, _x));
			}
			if((arr[y][x] == arr[_y][_x]) && (minT[_y][_x] > minT[y][x])){
				minT[_y][_x] = minT[y][x];
				que.push(hsh(_y, _x));
			}

		}
	}
	/*
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cout << minT[i][j] << " \n"[j == M];
		}
	}
	*/
	int cnt = 0;
	while(Q--){
		cnt++;
		cin >> y >> x >> t;
		if(cnt == 3 && N >= 500){
			cout << "minT=" << minT[y][x] << ",y="<<y<<",x="<<x<<",";
		}
		if(t > minT[y][x]){
			cout << (arr[y][x] ^ ((t - minT[y][x]) % 2)) << endl;	
		} else {
			cout << arr[y][x] << endl;
		}
	}
}

