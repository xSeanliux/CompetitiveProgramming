#include <iostream>
using namespace std;

const int maxN = 50;

char mp[maxN + 10][maxN];
int K;

int main(){
	cin >> K;
	cout << maxN + 1<< " " << maxN << endl;
	for(int i = 0; i <= maxN; i++) for(int j = 0; j < maxN ;j++) mp[i][j] = ' ';
	for(int i = 0; i < maxN / 7 * 7; i += 7){
		mp[i][i / 7] = '(';
		mp[i][i / 7 + 1] = ')';
		mp[i + 1][i / 7 + 1] = '(';
		mp[i + 1][i / 7] = ')';

		mp[i + 2][i / 7 + 1] = ')';
		mp[i + 3][i / 7 + 1] = '(';
		mp[i + 4][i / 7 + 1] = ')';
		mp[i + 5][i / 7 + 1] = '(';
		mp[i + 6][i / 7 + 1] = ')';
		if(((i / 7) & 1) == 0){
			if((K >> (i / 7)) & 1){
				bool f = 1;
				for(int j = i / 7 + 2; j < maxN; j++){
					mp[i][j] = f ? '(' : ')';
					f ^= 1;
				}
			}
			if((K >> (i / 7 + 1)) & 1){
				bool f = 1;
				for(int j = i / 7 + 2; j < maxN; j++){
					mp[i + 4][j] = f ? '(' : ')';
					f ^= 1;
				}
			}
		}
	}
	for(int i = 0; i <= maxN; i++){
		mp[i][maxN - 1] = i & 1 ? '(' : ')';
		if(mp[i][maxN - 2] == ' ') mp[i][maxN - 2] = '(';
	}
	for(int i = 0; i <= maxN; i++) for(int j = 0; j < maxN; j++) if(mp[i][j] == ' ') mp[i][j] = ')';
	for(int i = 0; i <= maxN; i++) for(int j = 0; j < maxN ;j++) cout << mp[i][j] << (j == maxN - 1 ? "\n" : "");
}
