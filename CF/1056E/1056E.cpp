#include <iostream>
#include <string.h>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7, b = 137, maxN = 1e6 + 10;

string s, t;
int zc, oc, hsh[maxN], x[maxN];

inline void Hash(){
	hsh[t.length()] = 0;
	for(int i = t.length() - 1; i >= 0; i--){
		hsh[i] = ((t[i] - 'a' + 1) + hsh[i + 1] * b) % MOD;
	}
}

inline int getHash(int l, int r){ //[l, r);
	return (hsh[l] - hsh[r] * x[r - l] % MOD + MOD) % MOD;
}

signed main(){
	x[0] = 1;
	cin >> s >> t;
	for(int i = 1; i < maxN; i++) x[i] = x[i - 1] * b % MOD;
	for(char c : s){
		(c == '0' ? zc : oc)++;
	}
	Hash();
	int ans = 0;
	for(int lz = 1; lz < t.length() && t.length() - lz * zc > 0; lz++){
		if((t.length() - lz * zc) % oc) continue;
		int lo = (t.length() - lz * zc) / oc, hz = -1, ho = -1, ci = 0;
		bool f = true;
		for(char c : s){
			if(c == '0'){
				if(hz == -1){
					hz = getHash(ci, ci + lz);
				} else if(hz != getHash(ci, ci + lz)){
					f = false;
					break;
				}
				ci += lz;
			} else {
				if(ho == -1){
					ho = getHash(ci, ci + lo);
				} else if(ho != getHash(ci, ci + lo)){
					f = false;
					break;
				}
				ci += lo;
			}
		}
		if(f){
			//cout << "Good: lz = " << lz << ", lo = " << lo << ", hz = " << hz << ", ho = " << ho << endl;
		}
		ans += (f && ho != hz);
	}
	cout << ans << endl;
}
