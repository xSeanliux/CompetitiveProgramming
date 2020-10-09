#include <iostream>
#include <string.h>
#include <fstream>
#define cin infile
#define cout outfile
using namespace std;

const int maxN = 326;

int mp[maxN][maxN], N, M, ans;
string s;

ifstream infile;
ofstream outfile;

int main(){
	infile.open("fortmoo.in");
	outfile.open("fortmoo.out");
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> s;
		for(int j = 1; j <= M; j++){
			mp[i][j] = (s[j - 1] == 'X');
			if(j) mp[i][j] += mp[i][j - 1];
		}
	}
	for(int l = 1; l <= M; l++){
		for(int r = l; r <= M; r++){
			int u = N + 1, d = -1;
			for(int i = 0; i < N; i++){
				if((mp[i][r] - mp[i][r - 1]) || (mp[i][l] - mp[i][l - 1])){
					u = N + 1, d = -1;
				}
				if(mp[i][r] - mp[i][l - 1] == 0){
					d = max(d, i);
					u = min(u, i);
				}
				ans = max(ans, (r - l + 1) * (d - u + 1));
			}
		}
	}
	cout << ans << endl;
}

