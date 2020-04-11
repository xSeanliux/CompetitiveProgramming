#include <iostream>
#include <string.h>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

const int maxN = 1e6 + 10;
int N, k, pre[maxN];
string s;
vector<vector<int> > ans;
vector<int> res;
deque<int> dq;

int main(){
	cin >> N >> k;
	cin >> s;
	s = '$' + s;
	for(int i = 1; i <= N; i++){
		pre[i] = pre[i - 1];
		if(s[i] == 'c') pre[i] -= k;
		else pre[i]++;
	}
	for(int i = 1; i <= N; i++){
		if(dq.size() >= k && pre[dq[dq.size() - k] - 1] == pre[i]){
			vector<int>().swap(res);
			res.push_back(i);
			for(int j = 0; j < k; j++){
				res.push_back(dq.back());
				dq.pop_back();
			}
			reverse(res.begin(), res.end());
			ans.push_back(res);
		} else {
			dq.push_back(i);
		}
	}
	reverse(ans.begin(), ans.end());
	for(vector<int> v : ans){
		for(int x : v){
			cout << x << " ";
		}
		cout << endl;
	}
}
