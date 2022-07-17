#include "interactive.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int maxN = 326;

int ans[maxN], choose[maxN];

vector<int> sets[7][2], all;

inline vector<int> sub(vector<int> &A, vector<int> &B){
	multiset<int> s;
	vector<int> res = vector<int>();
	for(int x : A) s.insert(x);
	for(int x : B) if(s.count(x)){
		s.erase(s.find(x));
	}
	for(int x : s) res.push_back(x);
	return res;
}

inline vector<int> uni(vector<int> &A, vector<int> &B){
	multiset<int> s;
	vector<int> res = vector<int>();
	for(int x : A) s.insert(x);
	for(int x : B) if(s.count(x)){
		res.push_back(x);
		s.erase(s.find(x));
	}
	return res;
}

vector<int> guess(int n) {
	vector<int> without, with;
	for(int i = 2; i <= n; i++) without.push_back(i);
	with = without;
	with.push_back(1);
	ans[1] = ask(1);
	with = get_pairwise_xor(with);
	without = get_pairwise_xor(without);
	//cout << "with = "; for(int x : with) cout << x << " "; cout << endl;
	//cout << "without = "; for(int x : without) cout << x << " "; cout << endl;
	all = sub(with, without);
	for(int &x : all) x ^= ans[1];
	//cout << "all = "; for(int x : all) cout << x << " "; cout << endl;

	
	for(int b = 0; (1 << b) <= n; b++){
		//cout << "b = " << b << endl;
		without = vector<int>();
		with = vector<int>();
		for(int i = 2; i <= n; i++){
			//cout << "i = " << i << endl;
			if((((i >> b) ^ (b == 0)) & 1) == 0){
				without.push_back(i);
				//cout << "pushing : " << i << endl;
			}
		}
		with = without;
		with.push_back(1);
		with = get_pairwise_xor(with);
		without = get_pairwise_xor(without);
		with = sub(with, without);
		for(int &x : with) x ^= ans[1];
		sets[b][b == 0] = with;
		sets[b][b != 0] = sub(all, with);
		//cout << b << "/0 = "; for(int x : sets[b][0]) cout << x << " "; cout << endl;
		//cout << b << "/1 = "; for(int x : sets[b][1]) cout << x << " "; cout << endl;
	}

	for(int i = 2; i <= n; i++){
		vector<int> cand = all;
		for(int b = 0; (1 << b) <= n; b++){
			cand = uni(cand, sets[b][((i >> b) & 1)]);
		}
		ans[i] = cand[0];
	}
	vector<int> res;
	for(int i = 1; i <= n; i++) res.push_back(ans[i]);
	return res;
}
