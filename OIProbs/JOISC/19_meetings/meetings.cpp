#include "meetings.h"
#include <iostream>
#include <random>
#include <chrono>
#include <map>	
#include <algorithm>
#include <vector>
using namespace std;
 
const int maxN = 2e3 + 326;
vector<int> adj[maxN];

void addEdge(int a, int b){
	//cout << "Adding: " << a << ", " << b << endl;
	if(a > b) Bridge(b, a);
	else Bridge(a, b);
}
 
void solve(vector<int> vec){
	if(vec.size() == 1) return;
	if(vec.size() == 2){
		addEdge(vec[0], vec[1]);
		return;
	}
	//cout << "vec = "; for(int x : vec) cout << x << " "; cout << endl;
	map<int, vector<int>> mp;
	vector<int> nv = vector<int>();
	int a = vec[0], b = vec[1];
	for(int i = 2; i < vec.size(); i++){
		int res = Query(a, b, vec[i]);
		if(res == a) a = vec[i];
		if(res == b) b = vec[i];
	}
	//cout << "a = " << a << ", b = " << b << endl;
	mp[a] = mp[b] = vector<int>();
	mp[a].push_back(a);
	mp[b].push_back(b);
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] == a || vec[i] == b) continue;
		int res = Query(a, b, vec[i]);
		if(!mp.count(res)) mp[res] = vector<int>();
		mp[res].push_back(vec[i]);
	}
	for(auto [x, v] : mp){
		//cout << "x = " << x << ", v = "; for(int y : v) cout << y << " "; cout << endl;
		solve(v);
		if(x != a && x != b) nv.push_back(x);
	}
	sort(nv.begin(), nv.end(), [&](int x, int y){
		return Query(a, x, y) == x;
	});
	//cout << "OK\n";
	//cout << "nv = " << nv.size() << ", vec: " << vec.size() << endl;
	if(nv.size()){
		for(int i = 0; i < nv.size() - 1; i++) addEdge(nv[i], nv[i + 1]);
		addEdge(a, nv[0]);
		addEdge(b, nv[nv.size() - 1]);
	} else addEdge(a, b);
}
 
void Solve(int N){
	vector<int> jizz = vector<int>();
	for(int i = 0; i < N; i++) jizz.push_back(i);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  	shuffle (jizz.begin(), jizz.end(), std::default_random_engine(seed));
	solve(jizz);
}
