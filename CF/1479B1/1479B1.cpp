#include <iostream>
#include <deque>
using namespace std;

const int maxN = 2e5 + 326;
int N, vals[maxN];
deque<int> put[2];

int main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> vals[i];
	for(int i = 0; i < N; i++){
		if(put[0].size() && put[0].back() == vals[i]) put[1].push_back(vals[i]);
		else if(put[1].size() && put[1].back() == vals[i]) put[0].push_back(vals[i]);
		else if(i < N - 1 && put[1].size() && put[1].back() == vals[i + 1]) put[1].push_back(vals[i]);
		else if(i < N - 1 && put[0].size() && put[0].back() == vals[i + 1]) put[0].push_back(vals[i]);
		else put[0].push_back(vals[i]);
	}
	int ans = 0;
	for(int i = 0; i < 2; i++){
		for(int j = 1; j < put[i].size(); j++) ans += (put[i][j] != put[i][j - 1]);
		ans += (put[i].size() > 0);
	}
	cout << ans << endl;
}
