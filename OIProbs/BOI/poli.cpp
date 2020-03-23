#include <iostream>
using namespace std;

int N, M, K;

int main(){
	cin >> N >> K;
	if(K == 1){
		cout << 1 << endl;
		return 0;
	}
	bool has = false;
	int k, n;
	for(int i = 0; i < N; i++){
		cin >> k;
		has |= k;
		for(int j = 0; j < k; j++) cin >> n;
	}
	if(has) cout << 2 << endl;
	else cout << 1 << endl;
}
