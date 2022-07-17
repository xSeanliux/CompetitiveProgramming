#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 2e5 + 326;
int N, x, arr[maxN], ans;

int main(){
	cin >> N >> x;
	ans = N;
	for(int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	
	int r = N - 1;
	for(int l = 0; l < r; l++){
		while(r - l > 1 && arr[l] + arr[r] > x) r--;
		if(arr[l] + arr[r] <= x){
			ans--;
			r--;
		} else break;
	}
	cout << ans << endl;
}
