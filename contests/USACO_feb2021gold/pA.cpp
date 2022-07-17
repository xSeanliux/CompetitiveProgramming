#include <iostream>
using namespace std;

const int maxN = 1e3 + 326;
int has[2003], sg[maxN], arr[maxN], N;

int main(){
	sg[0] = 0;
	sg[1] = 1;
	int mx = 0;
	for(int i = 1; i < maxN; i++){
		//cout << "i = " << i << endl;
		for(int j = max(1, i / 1000); j <= i; j++){
			j = (i / (i / j));
			has[sg[i / j - 1]]++;
		}
		bool f = true;
		for(int j = 0; f; j++) if(!has[j]){
			sg[i] = j;
			mx = max(mx, sg[i]);
			//cout << "sg(" << i << ") = " << sg[i] << endl;
			f = false;
		}
		for(int j = max(1, i / 1000); j <= i; j++){
			j = (i / (i / j));
			has[sg[i / j - 1]]--;
		}
	}
	cin >> N;
	int ans = 0;
	for(int i = 0; i < N; i++) cin >> arr[i];
	int x = 0;
	for(int i = 0; i < N; i++){
		for(int d = 1; d <= arr[i]; d++){
			//dividing by 
			x = 0;	
			for(int j = 0; j < N; j++){
				if(i == j){
					x ^= sg[arr[j] / d - 1];
				} else {
					x ^= sg[arr[j] / d];
				}
			}
			if(!x) ans++;
		}
	}
	cout << ans << endl;
}
