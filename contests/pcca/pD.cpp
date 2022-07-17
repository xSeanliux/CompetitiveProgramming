#include <iostream>
using namespace std;

int main(){
	int N, res;
	cin >> N;
	int topAt = 0, botAt = 0, mxCnt = 0;
	for(int i = 0; i < N; i++){
		cout << "? 0 " << i << endl;
		cin >> res;
		if(res == N){
			topAt = i;
			mxCnt++;
		}
	}
	if(mxCnt == N){ //a[0] == N
		mxCnt = 0;
		topAt = 0;
		for(int i = 0; i < N; i++){
			cout << "? 1 " << i << endl;
			cin >> res;
			if(res == N){
				botAt = i;
				mxCnt++;
			}
		}
	} else { //b[topAt] == N
		swap(botAt, topAt);
		topAt = 0;
		int k = (botAt + 1) % N;
		for(int i = 0; i < N; i++){
			cout << "? " << i << " " << k << endl;
			cin >> res;
			if(res == N){
				topAt = i;
			}
		}
	}
	//cout << "topAt = " << topAt << ", botAt = " << botAt << endl;
	cout << "! " << (botAt - topAt + N) % N << endl;
}
