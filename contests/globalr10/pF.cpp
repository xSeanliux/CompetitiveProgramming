#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 1e6 + 326;
int pre[maxN], N, h[maxN], sum, s2;

struct Obj{
	int l, r, type;
}

signed main(){
	ericxiao;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> h[i];
		sum += h[i];
	}
	for(int i = 1; i < N; i++){
		if(i && ((h[i] ^ h[i - 1]) & 1)){
			pre[i]++;
		}
	}
	for(int i = 1; i < N; i++){
		pre[i] += pre[i - 1];
		s2 += pre[i];
	}
	int st = (sum - s2) / N;
	for(int i = 0; i < N; i++){
		cout << st + pre[i] << " \n"[i == N - 1];
	}
}
