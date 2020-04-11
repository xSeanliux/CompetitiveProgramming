#include <iostream>
#include <map>
#define int long long int
using namespace std;

const int maxN = 2e5 + 10;
int N, arr[maxN], pre[maxN], ans;

map<int, int> mx;

signed main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> pre[i];
		pre[i] += pre[i - 1];
	}
	int r = 1;
	mx[0] = 0;
	for(int i = 1; i <= N; i++){
		if(mx.count(pre[i])){
			r = max(r, mx[pre[i]] + 2);
		}
		mx[pre[i]] = i;
		ans += (i - r + 1);
	}
	cout << ans << endl;
}


