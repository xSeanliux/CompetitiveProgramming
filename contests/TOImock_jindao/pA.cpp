#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int M = 1e9 + 7, I2 = 5e8 + 4;

int T;
string s;



signed main(){
	cin >> T;
	while(T--){
		cin >> s;
		int N = s.length();
		int ans = (s[N - 1] == '1'), currol = 2;
		for(int i = N - 2; i >= 0; i--){
			if(s[i] == '1'){	
				int k = (currol - ans - 1 + M) % M;
				ans = (ans + 2 * k + 1) % M; 
			}
			currol = 2 * currol % M;
		}
		cout << ans << endl;
	}
}


