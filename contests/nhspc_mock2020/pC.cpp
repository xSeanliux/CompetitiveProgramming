#pragma gcc optimize("Ofast", "unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 5e5 + 326;
int A, B, C, D, E, F, G, H, I, p, r1, r2;
int Sqrt[maxN], inv[maxN];

vector<pii> sols;

inline void solve(int a, int b, int c, int &r1, int &r2){
	//r1, r2 in 0 ~ p - 1 : two roots
	//-1 means no root
	//p means infinite roots
	if(a){
		int D = (b * b % p + p - 4 * a * c % p) % p;
		if(Sqrt[D] == -1){
			r1 = r2 = -1;
			return;
		}
		D = Sqrt[D];
		r1 = (inv[2 * a % p]) * (D - b + p) % p; //if p = 2 this doesn't work
		D = (p - D) % p;
		r2 = (inv[2 * a % p]) * (D - b + p) % p;
		return;
	}
	if(b){ //bz + c = 0
		r1 = (p - c) * inv[b] % p;	
		r2 = -1;
		return;
	} 
	if(c){
		r1 = r2 = -1;
		return;
	}
	r1 = r2 = p;
	return;
}

/*
 * 1 0 0 0 2 0 0 1 0 2
 */


signed main(){
	cin >> A >> B >> C >> D >> E >> F >> G >> H >> I >> p;
	if(p == 2){
		cout << "0 0\n";
		if((D + G + I) % 2 == 0) cout << "0 1\n";
		if((A + E + H) % 2 == 0) cout << "1 0\n";
		if((A + B + C + D + E + F + G + H + I) % 2 == 0) cout << "1 1\n";
		return 0;
	}
	fill(Sqrt, Sqrt + p, -1);
	inv[1] = 1;
	for(int i = 2; i < p; i++){
		inv[i] = (p - p / i) * inv[p % i] % p;
	}
	for(int i = 0; i < p; i++){
		Sqrt[i * i % p] = i;
	}
	//y = 0
	sols.emplace_back(0, 0);
	//Ax^2 + Ex + H	
	solve(A % p, E % p, H % p, r1, r2);
	if(r1 == p){
		for(int i = 0; i < p; i++) sols.emplace_back(i, 0);
	} else if(r1 != -1){
		sols.emplace_back(r1, 0);
		if(r2 != -1) sols.emplace_back(r2, 0);
	}
	//y != 0
	for(int w = 0; w < p; w++){
		int a = (H * w + I) % p;
		int b = (E * w * w + F * w + G) % p;
		int c = (((A * w * w) % p) * w + B * w * w + C * w + D) % p;
		//cout << "w = " << w << endl;
		solve(a, b, c, r1, r2);	
		//cout << "roots: " << r1 << ", " << r2 << endl;
		if(r1 == p){
			for(int z = 1; z < p; z++){
				sols.emplace_back(w * inv[z] % p, inv[z]);
			}
		} else if(r1 != -1){
			if(r1 != 0) sols.emplace_back(w * inv[r1] % p, inv[r1]);
			if(r2 != -1 && r2 != 0){
				sols.emplace_back(w * inv[r2] % p, inv[r2]);
			}
		}
	}
	sort(sols.begin(), sols.end());
	int k = unique(sols.begin(), sols.end()) - sols.begin();
	for(int i = 0; i < k; i++) cout << sols[i].F << " " << sols[i].S << '\n';
}
