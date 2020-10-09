#include <iostream>
#define int long long int
using namespace std;

const int maxN = 1e5 + 10;
int N, arr[maxN], val[maxN]; //+-/maxmin
bool jizz[maxN];

inline int Abs(int x){
	return (x < 0 ? -x : x);
}

signed main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
	val[N - 1] = arr[N - 1];
	jizz[N - 1] = 1;
	for(int i = N - 2; i >= 0; i--){
		if(val[i + 1] - arr[i] < 0){
			jizz[i] ^= 1;
		}
		val[i] = Abs(val[i + 1] - arr[i]);
	}
	for(int i = 0; i < N; i++){
		if(i) jizz[i] ^= jizz[i - 1];
		if(jizz[i]) cout << '+';
		else cout << '-';
	}
}

