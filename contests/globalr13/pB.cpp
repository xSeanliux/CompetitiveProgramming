#include <iostream>
using namespace std;


const int maxN = 1e5 + 326;
inline int Abs(int x){
	return x < 0 ? -x : x;
}

int T, N, arr[maxN], u, v;

int main(){
	cin >> T;
	while(T--){
		cin >> N >> u >> v;
		for(int i = 1; i <= N; i++) cin >> arr[i];
		bool alls = true;
		for(int i = 1; i <= N; i++) alls &= (arr[i] == arr[1]);
		bool f = false;
		for(int i = 2; i <= N && !f; i++){
			if(Abs(arr[i] - arr[i - 1]) >= 2){
				f = true;
				cout << 0 << endl;
				break;
			}
		}
		if(f) continue;
		int ans;
		if(!alls) ans = min(v, u);
		else ans = v + min(v, u);
		cout << ans << endl;
	}
}
