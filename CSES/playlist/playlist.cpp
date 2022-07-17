#include <iostream>
#include <algorithm>
using namespace std;


const int maxN = 2e5 + 326;
int N, arr[maxN], cnt[maxN], lisan[maxN];

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		lisan[i] = arr[i];
	}
	sort(lisan, lisan + N);
	int sz = unique(lisan, lisan + N) - lisan;
	for(int i = 0; i < N; i++){
		arr[i] = lower_bound(lisan, lisan + sz, arr[i]) - lisan;
	}
	int r = 0;
	int ans = 0;
	for(int l = 0; l < N; l++){
		while(r < N && !cnt[arr[r]]){
			cnt[arr[r]]++;
			r++;
		}
		ans = max(ans, r - l);
		if(r > l) cnt[arr[l]]--;
	}
	cout << ans << endl;
}
