#include <iostream>
#include <vector>
#define int long long int
using namespace std;

int u, v;

vector<int> getAns(int X, int S){
	vector<int> res;
	if(!X && !S) return res;
	if(!X){
		if(S & 1){
			res.push_back(1);
		}
		res.push_back(S / 2);
		res.push_back(S / 2);
	} else {
		res = getAns(0, S - X);
		for(int &x : res){
			if(!(x & X)){
				x ^= X;
				return res;
			}	
		}
		res.push_back(X);
	}
	return res;
}

signed main(){
	cin >> u >> v;
	if(u > v || (v - u) & 1){
		cout << -1 << endl;
		return 0;
	}
	vector<int> res = getAns(u, v);
	cout << res.size() << endl;
	for(int x : res) cout << x << " ";
	cout << endl;
}
