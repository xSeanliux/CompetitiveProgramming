#include <iostream>
#include <deque>
#include <algorithm>
#define int long long int
using namespace std;

const int maxN = 22;
int N, x, vals[maxN], ind[maxN], ans[maxN];

signed main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> vals[i];
		ind[i] = i;
	}
	sort(ind, ind + N, [](int a, int b){
		return vals[a] < vals[b];
	});
	for(int i = 0; i < N; i++){
		ans[ind[i]] = vals[ind[(i - 1 + N) % N]];
	}
	for(int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
}
