#include <iostream>
#include <vector>
using namespace std;

int T;

inline void solve(){
	int found, N, res;
	cin >> N;
	vector<int> ans = vector<int>();
	for(int i = 2; i <= N; i++){
		cout << "? 1 " << i - 1 << endl;
		cout << i << endl;
		for(int j = 1; j < i; j++) cout << j << " "; cout << endl;
		cin >> res;
		if(res != 0){
			for(int j = i + 1; j <= N; j++){
				cout << "? 1 1" << endl;
				cout << j << endl; 
				cout << i << endl;
				cin >> res;
				if(res == 0) ans.push_back(j);
			}
			int l = 0, r = i - 1, m;
			while(r - l > 1){
				int m = (l + r) / 2;
				cout << "? 1 " << m << endl;
				cout << i << endl;
				for(int j = 1; j <= m; j++) cout << j << " "; cout << endl;
				cin >> res;
				if(res == 0) l = m;
				else r = m;
			}
			for(int j = 1; j < i; j++) if(j != r) ans.push_back(j);
			cout << "! " << ans.size(); for(int x : ans) cout << " " << x; cout << endl;
			return;
		}
	}
}
int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
