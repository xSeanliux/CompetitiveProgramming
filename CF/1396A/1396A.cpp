#include <iostream>
#define int long long int
using namespace std;

const int maxN = 1e5 + 326;
int N, arr[maxN];

signed main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
	if(N == 1){
		cout << "1 1\n" << -arr[0] << "\n1 1\n0\n1 1\n0\n";
		return 0;
	}
	cout << "1 " << N << endl;
	for(int i = 0; i < N; i++) cout << -arr[i] * N << " \n"[i == N - 1];
	cout << "1 " << N - 1 << endl;
	for(int i = 0; i < N - 1; i++) cout << arr[i] * (N - 1) << " \n"[i == N - 2];
	cout << N << " " << N << endl;
	cout << arr[N - 1] * (N - 1) << endl;
}
