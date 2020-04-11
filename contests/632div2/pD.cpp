#include <iostream>
#include <string.h>
#include <queue>
#include <deque>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 5000;

int N, k, mx;
string s, news;
vector<int> tocheck, nxtcheck;
vector<int> swaps[maxN];
deque<vector<int> > ans;

int main(){
	cin >> N >> k >> s;
	bool toCheck = true;
	int l = 0;
	while(toCheck){
		toCheck = false;
		news = s;
		for(int i = 0; i < N - 1; i++){
			if(s[i] == 'R' && s[i + 1] == 'L'){
				swap(news[i], news[i + 1]);
				swaps[l].push_back(i);
				mx++;
				toCheck = true;
			}
		}
		s = news;
		l++;
	}
	l--;
	/*
	for(int i = 0; i < l; i++){
		cout << "i = " << i << endl;
		for(int x : swaps[i]){
			cout << x << " ";
		}
		cout << endl;
	}
	*/
	//cout << "mx = " << mx << ", l = " << l << endl;
	if(k > mx || k < l){
		cout << -1 << endl;
		return 0;
	}
	vector<int> curvec;
	bool f = false;
	for(int i = 0; i < l && !f; i++){
		for(int j = 0; j < swaps[i].size() && !f; j++){
			if(ans.size() + (l - i) == k){
				//cout << "2 at i = " << i << ", j = " << j << endl;
				//cout << "anssize = " << ans.size() << endl;
				for(int k = j; k < swaps[i].size(); k++){
					curvec.push_back(swaps[i][k]);
				}
				ans.push_back(curvec);
				for(int k = i + 1; k < l; k++){
					ans.push_back(swaps[k]);
				}
				f = true;
				break;
			} else {
				curvec.push_back(swaps[i][j]);
				ans.push_back(curvec);
				curvec.clear();
			}
		}
	}
	for(vector<int> v : ans){
		cout << v.size();
		for(int x : v){
			cout << " " << x + 1;
		}
		cout << '\n';
	}
}
