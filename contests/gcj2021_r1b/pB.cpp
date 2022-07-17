#include <iostream>
#include <map>
#define int long long int
using namespace std;

int T, A, B, N, x, c = 0, arr[1000];



inline bool alone(){
	int cnt = 0;	
	for(int i = 0; i < 326; i++) if(arr[i]) cnt++;
	return (cnt == 1);
}

inline void solve(){
	cin >> N >> A >> B;
	fill(arr, arr + 326, 0);
	for(int i = 1; i <= N; i++) cin >> arr[i];
	for(int i = 1; i <= 326; i++){
		cout << "i = " << i << endl;
		for(int j = 1; j < 10; j++){
			cout << arr[j] << " \n"[j == 9];
		}
		if(arr[i]){
			if(alone()){
				if(arr[i] == 1){
					cout << "Case #" << ++c << ": " << i << endl;
					return;
				} else {
					cout << "Case #" << ++c << ": IMPOSSIBLE" << endl;
					return;
				}
			} else {
				if(arr[i] <= arr[i + 1]){
					arr[i + 2] += arr[i];
					arr[i + 1] -= arr[i];
					arr[i] = 0;
				} else {
					arr[i + 2] += arr[i];
					arr[i] = arr[i + 1] = 0;
				}
			}
		}
		for(int j = 1; j < 10; j++){
			cout << arr[j] << " \n"[j == 9];
		}
	}
}
signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}

