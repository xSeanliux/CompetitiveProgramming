#include "lib0011.h"
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int can[(1 << 20) + 326];
int64_t solve(vector<int> ans) {
	can[0] = 1;
	for(int x : ans) can[x] = 1;
	int r = 0;
	for(int i = (1 << 20); i >= 0; i--){
		if(can[i]){
			r++;
			for(int x : ans) can[i & x] = 1;
		}
	}
	return r;
}

/*
int main(){
	int N, x;
	cin >> N;
	vector<int> v;
	v.resize(N);
	for(int i = 0; i < N; i++) cin >> v[i];
	cout << solve(v);
}
*/
