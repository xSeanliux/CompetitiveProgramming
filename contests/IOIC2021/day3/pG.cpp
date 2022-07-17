#include <iostream>
#include <iomanip>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e6 + 326;
int T, N, fail[maxN], z[maxN], far[maxN];

inline void solve(){
	cin >> N;
	z[0] = N;
	fill(far, far + N, -1);
	fill(z, z + N, 0);
	for(int i = 0; i < N; i++){
		cin >> fail[i];	
		if(fail[i] >= 0){
			far[i - fail[i]] = max(far[i - fail[i]], i);
		}
	}
	for(int i = 1; i < N; i++){
		far[i] = max(far[i], far[i - 1]);
	}
	for(int i = 1; i < N; i++){
		if(far[i] < i || fail[i] == -1){
			z[i] = 0;
			continue;
		}
		if(i == far[i] - fail[far[i]]) z[i] = far[i] - i + 1;
		else z[i] = z[i - (far[i] - fail[far[i]])]; 
	}
	for(int i = 0; i < N; i++){
		cout << z[i] << " \n"[i == N - 1];
	}
}
int main(){
	cout << fixed << setprecision(0);
	ericxiao
	cin >> T;
	while(T--){
		solve();
	}
}
