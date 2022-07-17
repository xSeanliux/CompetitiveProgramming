#include <iostream>
#include <string.h>
using namespace std;

const int N = 7;

string t;
char cur[N * N - 1], ch[4] = {'D', 'R', 'U', 'L'};
int a, tot, dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }, vis[N][N];

inline bool val(int y, int x){
	if(y < 0 || x < 0 || y >= N || x >= N || vis[y][x] == 1) return false;
	return true;
}

void col(int y, int x, int n){
	vis[y][x] = n;
	for(int d = 0; d < 4; d++){
		if(val(y + dir[d][0], x + dir[d][1]) && vis[y + dir[d][0]][x + dir[d][1]] != n) col(y + dir[d][0], x + dir[d][1], n);
	}
}

bool con(){
	int c = 0;
	for(int i = 0; i < N && c <= 1; i++) for(int j = 0; j < N && c <= 1; j++){
		if(!vis[i][j]){
			col(i, j, 2);
			c++;
		}
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
		if(vis[i][j] == 2){
			col(i, j, 0);
			break;
		}
	}
	return c <= 1;
}

void dfs(int now = 0, int y = 0, int x = 0, int fd = -1){
	//cout << "now: " << y << ", " << x << endl;
	if(y == N - 1 && x == 0){
		//cout << "now = " << now << endl;
		if(now == N * N - 1){
			/*
			cout << "\"";
			for(int i = 0; i < N * N - 1; i++) cout << cur[i];
			cout << "\",\n";
			*/
			a++;
			return;
		} else return;
	}
	if(~fd) if(!val(y + dir[fd][0], x + dir[fd][1]) && val(y + dir[(fd + 1) % 4][0], x + dir[(fd + 1) % 4][1]) && val(y + dir[(fd + 3) % 4][0], x + dir[(fd + 3) % 4][1])) return;
	for(int i = 0; i < 4; i++){
		if((t[now] == '?' || t[now] == ch[i]) && val(y + dir[i][0], x + dir[i][1])){
			vis[y + dir[i][0]][x + dir[i][1]] = true;
			cur[now] = ch[i];	
			dfs(now + 1, y + dir[i][0], x + dir[i][1], i);
			vis[y + dir[i][0]][x + dir[i][1]] = false;
		}
	}
}

int main(){
	cin >> t;
	vis[0][0] = true;
	dfs();	
	cout << a << endl;
}
