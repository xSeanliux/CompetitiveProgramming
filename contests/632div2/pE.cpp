#include <iostream>
#include <algorithm>
using namespace std;

int N, tmp[4][4] = {
{4, 3, 6, 12 },
{7, 5, 9, 15},
{14, 1, 11, 10}, 
{13, 8, 16, 2} 
};

int main(){
	cin >> N;
	if(N == 3){
		cout << "1 2 4\n5 3 8\n9 6 7\n";
		return 0;
	}
	if(N < 3){
		cout << -1 << endl;
		return 0;
	}
	int cnt = 17;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i < 4 && j < 4) cout << tmp[i][j];
			else cout << cnt++;
			cout << " ";
		}
		cout << endl;
	}

}
