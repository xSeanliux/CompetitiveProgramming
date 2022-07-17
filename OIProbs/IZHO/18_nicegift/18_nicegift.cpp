#include <iostream>
#include <map>
#include <deque>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 1e6 + 326;

int N, K;

signed main(){
	cin >> N >> K;
	int x;
	cin >> x;
	for(int i = 1; i <= N; i++) cin >> x;
	if(N % K){
		cout << -1 << endl;
		return 0;
	}
	cout << N / K << endl;
	for(int i = 1; i <= N; i += K){
		cout << x << " ";
		for(int j = i; j < i + K; j++) cout << j << " ";
		cout << endl;
	}
}
