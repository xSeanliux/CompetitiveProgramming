#include <iostream>
#include <map>
#include <string.h>
#include <utility>
#include <deque>
#include <queue>
using namespace std;

map<string, int> mp;

int T, c = 0;

struct Obj{
	deque<int> que;	
	int totem;
	Obj(){
		que = deque<int>();
	}
	Obj(int x): totem(x){
		que = deque<int>();
	}
	inline void Not(){
		if(que.size() == 0){
			totem = 1;
			que.push_back(1);
			return;
		}
		totem -= que.front();
		que.pop_front();
	}
	inline void Double(){
		if(que.size() == 0) return;
		if(que.size() & 1) que.push_back(1);
		else que.back()++;
		totem++;
	}
	inline string hsh(){
		if(que.size() == 0) return "Z";
		string res = "";
		for(int x : que) res += to_string(x) + "/";
		return res;
	}
	inline int mxel(){
		int res = 0;
		for(int x : que) res = (x > res ? x : res);
		return res;
	}
};

Obj get(string s){
	Obj obj = Obj(s.length());
	char cur = '1';
	int num = 0;
	for(char c : s){
		if(c == cur) num++;
		else {
			obj.que.push_back(num);
			cur = c;
			num = 1;
		}
	}
	obj.que.push_back(num);
	return obj;
}

inline void solve(){
	string s, e;
	Obj S, E;
	mp = map<string, int>();	
	cin >> s >> e;
	S = get(s), E = get(e);
	queue<Obj> que;
	mp[S.hsh()] = 0;
	que.push(S);
	string tgt = E.hsh();
	Obj nf;
	while(que.size() && !mp.count(tgt)){
		Obj f = que.front(); que.pop();
		nf = f;
		nf.Not();
		if(nf.totem <= 25 && nf.que.size() <= 8 && nf.mxel() <= 8 && !mp.count(nf.hsh())){
			mp[nf.hsh()] = mp[f.hsh()] + 1;
			que.push(nf);
		}
		nf = f;
		nf.Double();
		if(nf.totem <= 25 && nf.que.size() <= 8 && nf.mxel() <= 8 && !mp.count(nf.hsh())){
			mp[nf.hsh()] = mp[f.hsh()] + 1;
			que.push(nf);
		}
	}
	cout << "Case #" << ++c << ": ";
	if(mp.count(tgt)) cout << mp[tgt] << endl;
	else cout << "IMPOSSIBLE" << endl;
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
