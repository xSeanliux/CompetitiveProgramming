#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

int m, d, N, curpos = 0;
vector<int> dists;

signed main(){
	cin >> m >> d >> N;
	dists.resize(N);
	for(int i = 0; i < N; i++) cin >> dists[i];
	sort(dists.begin(), dists.end());
	for(int i = 0; i < N; i++){
		if(dists[i] >= m - d){
			//cout << " i = " << i << endl;
			int cnt = 0;
			for(int j = N - 1; j >= 0; j--){
				//cout << "j = " << j << endl;
				if(j == i) continue;
				if(curpos < d && dists[i] < (d - curpos) * 2 + m - d){
					if(dists[j] <= d - curpos){
						cout << 0 << endl;
						return 0;
					}
					curpos += dists[j] - (d - curpos);
					cnt++;
					if(curpos >= m){
						cout << cnt << endl;
						return 0;
					}
				} else {
					cout << cnt + 1 << endl;
					return 0;
				}
			}
			if(curpos >= d || (curpos < d && (dists[i] >= (d - curpos) * 2 + m - d))) cout << cnt + 1 << endl;
			else cout << 0 << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}


