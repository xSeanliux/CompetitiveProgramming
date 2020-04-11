#include <iostream>
#include <algorithm>
#include <set>
#include <string.h>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 10;
set<int> toupdate, has;
set<int> rhs[maxN]; 
set<int, greater<int> > lhs[maxN];
int N, k, arr[maxN];
string s;
vector<vector<int> > ans, res;

void disp(){
	for(int x : has){
		cout << "For index " << x << " : ";
		cout << "lhs: ";
		for(int v : lhs[x]) cout << v << " ";
		cout << ", rhs: ";
		for(int v : rhs[x]) cout << v << " ";
		cout << endl;
	}
	cout << "toupdate: " << endl;
	for(int x : toupdate) cout << x << " ";
	cout << endl;
}

int main(){
	ericxiao;
	cin >> N >> k;
	cin >> s;
	for(int i = 0; i < N; i++){
		arr[i] = (s[i] == 'c');
	}
	for(int i = 0; i < N; i++){
		if(arr[i]){
			has.insert(i);
			for(int j = i + 1; j < N && !arr[j]; j++){
				rhs[i].insert(j);
			}
			for(int j = i - 1; j >= 0 && !arr[j]; j--){
				lhs[i].insert(j);
			}
			if(lhs[i].size() + rhs[i].size() >= k) toupdate.insert(i);
		}
	}
	/*
	cout << "has: " << endl;
	for(int x : has){
		cout << x << " ";
	}
	cout << endl;
	*/
	int pos, nxt, prv;
	for(int i = 0; i < N / (k + 1); i++){
		pos = *toupdate.begin();
		//cout << "pos = " << pos << endl;
		toupdate.erase(pos);
		nxt = (pos == *has.rbegin()) ? -1 : *has.upper_bound(pos);
		prv = (pos ==  *has.begin()) ? -1 : *(--has.lower_bound(pos)); 
		has.erase(pos);
		//cout << "nxt = " << nxt << ", prv = " << prv << endl;
		//disp();
		vector<int>().swap(res);
		for(int x : lhs[pos]){
			if(res.size() == k){
				if(nxt != -1){
					lhs[nxt].insert(x);	
				}
			} else {
				if(prv != -1) rhs[prv].erase(rhs[prv].find(x));
				res.push_back(x);
			}
		}
		if(res.size() < k){
			for(int x : rhs[pos]){
				if(res.size() == k){
					if(prv != -1){
						rhs[prv].insert(x);	
					}
				} else {
					if(nxt != -1) lhs[nxt].erase(lhs[nxt].find(x));
					res.push_back(x);
				}
			}
		}
		for(int x : res){
			if(lhs[pos].count(x)) lhs[pos].erase(x);
			if(rhs[pos].count(x)) rhs[pos].erase(x);
		}
		res.push_back(pos);
		ans.push_back(res);
		if(nxt != -1 && rhs[nxt].size() + lhs[nxt].size() >= k) toupdate.insert(nxt);
		if(prv != -1 && rhs[prv].size() + lhs[prv].size() >= k) toupdate.insert(prv);
		if(nxt != -1 && rhs[nxt].size() + lhs[nxt].size() < k && toupdate.count(nxt)) toupdate.erase(nxt); 
		if(prv != -1 && rhs[prv].size() + lhs[prv].size() < k && toupdate.count(prv)) toupdate.erase(prv);
		//disp();
		//cout << endl;
	}
	reverse(ans.begin(), ans.end());
	for(vector<int> v : ans){
		sort(v.begin(), v.end());
		for(int x : v){
			cout << x + 1 << " ";
		}
		cout << '\n';
	}

}
