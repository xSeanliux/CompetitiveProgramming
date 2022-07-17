#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 1e6 + 326;

vector<int> mp[2 * maxN], arr, d;

int N, M;
string s;

void manacher() { 
	//cout << "running: "; for(int x : arr) cout << x << " ";
	//cout << endl;
    for(int i = 0, l = 0, r = -1; i < (int)arr.size(); i++){
        int k = (i > r ? 1 : min(d[(r + l) - i], r - i + 1));
        while(i + k < (int)arr.size() && 0 <= i - k && arr[i + k] == arr[i - k]) k++;
        d[i] = k--;
        if(i + k > r){
            r = i + k;
            l = i - k;
        }
        //cout << "d[" << i << "] = " << d[i] << endl;
    }
}

struct Obj{
	int val, l, r;
	Obj(){}
	Obj(int v, int l, int r): val(v), l(l), r(r){}
};

signed main(){
	ericxiao;
	cin >> N >> M;
	d.resize(2 * N + 1);
	for(int i = 0; i < N; i++){
		mp[2 * i + 1].resize(M);
		mp[2 * i + 2].resize(M);
		cin >> s;
		for(int j = 0; j < M; j++) mp[2 * i + 1][j] = s[j] - '0';
		fill(mp[2 * i + 2].begin(), mp[2 * i + 2].end(), 2);
	}
	mp[0].resize(M);
	fill(mp[0].begin(), mp[0].end(), 2);
	for(int i = 0; i < M; i++){
		vector<int>().swap(arr);
		//cout << "OK?" << endl;
		for(int j = 0; j <= 2 * N; j++){
			//cout << "pushing " << mp[j][i] << endl;
			arr.push_back(mp[j][i]);
		}
		manacher();
		//cout << "manacher: "; for(int x : d) cout << x << " ";
		//cout << endl;
		for(int j = 0; j <= 2 * N; j++) mp[j][i] = (d[j]) / 2;
	}
	stack<Obj> stk;
	int ans = 0, s;
	//for(int i = 0; i <= 2 * N; i++) for(int j = 0; j < M; j++) cout << mp[i][j] << " \n"[j == M - 1];
	for(int i = 1; i < 2 * N; i++){
		s = 0;
		stk = stack<Obj>();
		for(int j = 0; j < M; j++){
			//cout << "mp[" << i << "][" << j << "] = " << mp[i][j] << endl;
			while(stk.size() && stk.top().val >= mp[i][j]){
				s -= stk.top().val * (stk.top().r - stk.top().l + 1);
				stk.pop();
			}
			int l = stk.size() ? stk.top().r + 1 : 0;
			s += mp[i][j] * (j - l + 1);
			//cout << "s = " << s << endl;
			stk.push(Obj(mp[i][j], l, j));
			ans += s;
		}
	}
	cout << ans << endl;
}
