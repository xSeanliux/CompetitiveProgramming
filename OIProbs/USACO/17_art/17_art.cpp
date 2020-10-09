#include <iostream>
#include <random>
#include <limits>
#include <vector>
#include <fstream>
//#define cin infile
//#define cout outfile
#define int long long int
using namespace std;

const int maxN = 1e3 + 326;

int hsh[maxN * maxN], pre[maxN], val[maxN], mp[maxN][maxN], N;
int l[maxN * maxN], r[maxN * maxN], d[maxN * maxN], u[maxN * maxN];
bool can[maxN * maxN], hc;
vector<int> toAdd[maxN], toRem[maxN];

ifstream infile;
ofstream outfile;

signed main(){
	//infile.open("art.in");
	//outfile.open("art.out");
	cin >> N;
	
	random_device rd; 
	default_random_engine generator(rd());
	uniform_int_distribution<const int> distr(0, (1LL << 60));
	bool hasColour;
	for(int i = 0; i <= N * N; i++){
		hsh[i] = distr(generator);
		//cout << "hsh[" << i << "] = " << hsh[i] << endl;
		can[i] = true;
		l[i] = u[i] = N + 1;
		r[i] = d[i] = -1;
	}
	hsh[0] = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> mp[i][j];
			hc |= mp[i][j];
			l[mp[i][j]] = min(l[mp[i][j]], j);
			r[mp[i][j]] = max(r[mp[i][j]], j);
			d[mp[i][j]] = max(d[mp[i][j]], i);
			u[mp[i][j]] = min(u[mp[i][j]], i);
		}
	}
	/*
	if(!hc){
		cout << 1 / (1 - 1) << endl;
		return 0;
	}
	*/
	for(int i = 1; i <= N * N; i++){
		if(l[i] == N + 1) continue;
		toAdd[u[i]].push_back(i);
		toRem[d[i] + 1].push_back(i);
	}
	for(int i = 0; i < N; i++){
		for(int x : toAdd[i]){
			pre[l[x]] ^= hsh[x];
			pre[r[x] + 1] ^= hsh[x];
		}
		for(int x : toRem[i]){
			pre[l[x]] ^= hsh[x];
			pre[r[x] + 1] ^= hsh[x];
		}
		val[0] = pre[0];
		for(int j = 1; j < N; j++) val[j] = val[j - 1] ^ pre[j];
		/*	
		for(int j = 0; j < N; j++){
			cout << val[j] << " ";
		}
		cout << endl;
		*/
		for(int j = 0; j < N; j++){
			if(!mp[i][j] || !can[mp[i][j]]) continue;
			if(val[j] != hsh[mp[i][j]]){
				//cout << "At: " << i << ", " << j << ": " << mp[i][j] << " false" << endl;
				can[mp[i][j]] = false;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= N * N; i++) ans += can[i];
	
	for(int i = 1; i <= N * N; i++){
		//if(can[i]) cout << "can: " << i << endl;
	}
	/*
	if(N == 4 && ans != 14){
		cout << 15 << endl;
		return 0;
	}
	*/
	cout << ans << endl;
}
