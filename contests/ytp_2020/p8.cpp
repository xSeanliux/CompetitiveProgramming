#include <iostream>
#include <string.h>
using namespace std;

char mp[6][6], tmp[6][6];
string s;

inline int chk(){
	int res = 0;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			if(tmp[i][j] == '.'){ //go from right
				bool canRight = true, canLeft = true;
				for(int k = j; k < 6; k++){
					if(tmp[i][k] == '#'){
						canLeft = false;
						break;
					}
				}
				for(int k = j; k >= 0; k--){
					if(tmp[i][k] == '#'){
						canRight = false;
						break;
					}
				}
				if(!canRight && !canLeft){
					return 7122;
				}
				res++;
				if(canRight){
					for(int k = 0; k < 6; k++){
						if(tmp[i][k] == '#') break;
						tmp[i][k] = 'V';
					}
				} else if(canLeft){
					for(int k = 5; k >= 0; k--){
						if(tmp[i][k] == '#') break;
						tmp[i][k] = 'V';
					}
				}
			}
		}
	}
	return res;
}


int main(){
	for(int i = 0; i < 6; i++){
		cin >> s;
		for(int j = 0; j < 6; j++){
			mp[i][j] = s[j];
		}
	}
	int ans = 7122, _ans;
	for(int msk = 0; msk < (1 << 12); msk++){
		for(int i = 0; i < 6; i++) for(int j = 0; j < 6; j++) tmp[i][j] = mp[i][j];
		_ans = 0;
		for(int i = 0; i < 12; i++){
			if((msk >> i) & 1){
				_ans++;
				if(i < 6){ //top
					for(int j = 0; j < 6; j++){
						if(tmp[j][i] == '#') break;
						tmp[j][i] = 'V';
					}
				} else {
					for(int j = 5; j >= 0; j--){
						if(tmp[j][i - 6] == '#') break;
						tmp[j][i - 6] = 'V';
					}

				}
			}
		}
		_ans += chk();
		ans = min(ans, _ans);
	}
	if(ans < 40) cout << ans << endl;
	else cout << -1 << endl;
}
