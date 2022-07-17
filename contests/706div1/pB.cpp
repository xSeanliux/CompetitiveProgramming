#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

const int maxN = 2e5 + 326;
int N, arr[maxN], inc[maxN][2], des[maxN][2];
vector<int> lowpoints;

int main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
	inc[0][0] = des[0][0] = 1;
	inc[N - 1][1] = des[N - 1][1] = 1;
	int mxinc = 1;
	for(int i = 1; i < N; i++){
		if(arr[i] > arr[i - 1]){
			des[i][0] = des[i - 1][0] + 1;
			inc[i][0] = 1;
		} else {
			des[i][0] = 1;
			inc[i][0] = inc[i - 1][0] + 1;
		}
		mxinc = max(mxinc, inc[i][0]);
	}
	for(int i = N - 2; i >= 0; i--){
		if(arr[i] > arr[i + 1]){
			des[i][1] = des[i + 1][1] + 1;	
			inc[i][1] = 1;
		} else {
			des[i][1] = 1;
			inc[i][1] = inc[i + 1][1] + 1;
		}
		mxinc = max(mxinc, inc[i][1]);
	}
	int slopecnt = 0;
	for(int i = 0; i < N; i++){
		slopecnt += inc[i][0] == mxinc;
		slopecnt += inc[i][1] == mxinc;
	}
	if(slopecnt == 1){
		cout << 0 << endl;
	} else if(slopecnt == 2){
		int ans = 0;
		for(int i = 0; i < N; i++){
			if(des[i][0] == mxinc && des[i][1] == mxinc){
				if(mxinc & 1) ans++;
			}
		}
		cout << ans << endl;
	} else {
		cout << 0 << endl;
	}
}
