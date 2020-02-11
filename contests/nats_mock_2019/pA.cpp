#include <iostream>
using namespace std;

const int maxN = 100;

int T, n, m, arr[maxN][maxN];

int main(){
	cin >> T;
	while(T--){
		cin >> n >> m;
		bool can = false;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> arr[i][j];
		for(int i = 0; i < n - 1; i++) for(int j = 1; j < m; j++) if(arr[i][j] == arr[i + 1][j - 1]) can = true;
		if(can) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
