#include <iostream>
#include <vector>
using namespace std;

const int maxN = 2e5 + 326;
vector<int> ans[maxN][2];

int N, arr[maxN << 1];

inline bool operator<(vector<int> &a, vector<int> &b){
	return a[0] < b[0];
}

inline vector<int> Merge(vector<int> &a, vector<int> &b){
	int k = 1, now = 0;
	vector<int> res = vector<int>();
	res.reserve(a.size() + b.size());
	while(true){
		int l = now + k;
		if(now >= a.size() && now >= b.size()) return res;
		for(int i = now; i < l && i < a.size(); i++) res.push_back(a[i]);
		for(int i = now; i < l && i < b.size(); i++) res.push_back(b[i]);
		now += k;
		k <<= 1;
	}
}

vector<int> solve(int cur){
	if(cur > N) return vector<int>();
	vector<int> res = vector<int>(), _res = vector<int>();
	res.reserve(ans[2 * cur][0].size() + ans[2 * cur + 1][0].size() + 1);
	if(arr[cur] < arr[2 * cur] && arr[cur] < arr[2 * cur + 1]){
		res.push_back(arr[cur]);
		_res = Merge(ans[2 * cur][0], ans[2 * cur][1]);
		for(int x : _res) res.push_back(x);
	}
	if(arr[2 * cur] < arr[cur] && arr[2 * cur] < arr[2 * cur + 1]){
		swap(arr[cur], arr[2 * cur]);
		res.push_back(arr[cur]);
		_res = solve(2 * cur);
		_res = Merge(_res, ans[2 * cur + 1][0]);
		for(int x : _res) res.push_back(x);
		swap(arr[cur], arr[2 * cur]);
	}
	if(arr[2 * cur + 1] < arr[cur] && arr[2 * cur + 1] < arr[2 * cur]){
		vector<int> _res2 = vector<int>();			
		//res
		swap(arr[cur], arr[2 * cur + 1]);
		vector<int> __r = solve(2 * cur + 1);
		__r = Merge(ans[2 * cur][0], __r);
		swap(arr[cur], arr[2 * cur + 1]);

		swap(arr[cur], arr[2 * cur]);
		_res2 = solve(2 * cur);
		_res2 = Merge(_res2, ans[2 * cur + 1][1]);
		swap(arr[cur], arr[2 * cur]);
		res.push_back(arr[2 * cur + 1]);
		if(__r < _res2){
			for(int x : __r) res.push_back(x);
		} else {
			for(int x : _res2) res.push_back(x);
		}	
	}
	return res;
}

int main(){
	fill(arr, arr + maxN * 2, maxN);
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> arr[i];
	for(int i = N; i; i--){
		ans[i][0] = solve(i);
		cout << "ans[" << i << "][0] = "; for(int x : ans[i][0]) cout << x << " "; cout << endl;
		if(i & 1 && i > 1){
			swap(arr[i], arr[i / 2 * 2]);
			ans[i][1] = solve(i);
			swap(arr[i], arr[i / 2 * 2]);
			cout << "ans[" << i << "][1] = "; for(int x : ans[i][0]) cout << x << " "; cout << endl;
		}
	}
	for(int x : ans[1][0]) cout << x << " ";
}
