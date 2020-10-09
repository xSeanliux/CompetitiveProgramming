#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 326;
int col[maxN], N, K, M, L, lm[maxN], rm[maxN];
vector<int> pos[maxN], ans, rig, lef;

int main(){
	ericxiao;
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> col[i];
		pos[col[i]].push_back(i);
	}
	cin >> M >> L;
	rig.resize(M);
	lef.resize(L);
	fill(rm, rm + N, -1);
	for(int i = 0; i < M; i++){
		cin >> rig[i];
		if(!i){
			for(int p : pos[rig[i]]){
				rm[p] = p;
			}
			continue;
		}
		int cpos = 0;
		for(int p : pos[rig[i]]){
			while(cpos + 1 < pos[rig[i - 1]].size() && pos[rig[i - 1]][cpos + 1] < p) cpos++;
			if(pos[rig[i - 1]].size() && pos[rig[i - 1]][cpos] < p) rm[p] = rm[pos[rig[i - 1]][cpos]]; 
		}
	}
	int cMax = -1;
	for(int i = 0; i < N; i++){
		if(col[i] == rig[M - 1]){
			cMax = max(cMax, rm[i]);
		}
		rm[i] = cMax;
	}
	for(int i = 0; i < L; i++){
		cin >> lef[i];
	}
	fill(lm, lm + N, maxN);
	for(int i = 0; i < L; i++){
		reverse(pos[lef[i]].begin(), pos[lef[i]].end());
		if(!i){
			for(int p : pos[lef[i]]){
				lm[p] = p;
			}
			continue;
		}
		int cpos = 0;
		for(int p : pos[lef[i]]){
			while(cpos + 1 < pos[lef[i - 1]].size() && pos[lef[i - 1]][cpos + 1] > p) cpos++;
			if(pos[lef[i - 1]].size() && pos[lef[i - 1]][cpos] > p) lm[p] = lm[pos[lef[i - 1]][cpos]]; 
		}
	}
	int cMin = maxN;
	for(int i = N - 1; i >= 0; i--){
		if(col[i] == lef[L - 1]){
			cMin = min(cMin, lm[i]);
		}
		lm[i] = cMin;
	}
	/*
	for(int i = 0; i < N; i++) cout << rm[i] << " ";
	cout << endl;
	for(int i = 0; i < N; i++) cout << lm[i] << " ";
	*/
	//cout << "Cols: " << endl;
	//for(int i = 0; i < N; i++) cout << col[i] << " ";
	//cout << endl;
	int curl = -1, curr = -1;
	for(int i = 0; i < N; i++){
		while(curl + 1 < rm[i]){
			curl++;
			if(pos[col[curl]].size() > 1) curr = max(curr, max(pos[col[curl]].back(), pos[col[curl]].front()));
		}
		//cout << "at i = " << i << endl;
		//cout << "lm = " << lm[i] << ", rm = " << rm[i] << ", col = " << col[i] << ", curr = " << curr << endl;
		if(lm[i] != maxN && rm[i] != -1 && col[i] == lef[L - 1] && lm[i] < curr){
			ans.push_back(i + 1);
		}
	}
	cout << ans.size() << endl;
	for(int x : ans) cout << x << " ";
	cout << endl;
}

