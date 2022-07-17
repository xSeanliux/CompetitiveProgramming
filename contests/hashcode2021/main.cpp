#include <vector>
#include <map>
#include <ctime>  
#include <iostream>
#include <cstdlib> 
#include <math.h>
#include <utility>
#define pb push_back
using namespace std;

int D, I, S, V, F;
struct Street {
  int B, E, L;
};
vector <Street> sts;        // street's information
map <string, int> st_name;  // street name
map <int, string> st_id;    // street id
vector <int> st_cnt, nxtwei;        // street used cnt
vector <vector<int>> it_in; // intersections indegree
vector <vector<int>> cars;  // car's goal


inline int wei(int x){
	return x;
}

struct Plan {
  int id, sze;
  vector <string> sts;
  vector <int> len;
  Plan(int i) : id(i) {}
};
vector <Plan> sol;

void init() {
  sts.resize(S);
  st_cnt.resize(S);
  cars.resize(V);
  it_in.resize(I);
  it_in.resize(S);
}

signed main() {
	srand(time(0));
  cin >> D >> I >> S >> V >> F;
  init();
  for (int i = 0; i < S; i++) {
	int B, E, L;
    string str;
    cin >> B >> E >> str >> L;
	sts[i].B = B;
	sts[i].E = E;
	sts[i].L = L;
    it_in[E].pb(i);
    st_name[str] = i;
    st_id[i] = str;
  }
  for (int i = 0; i < V; i++) {
    int P;
	vector<string> strs;
    cin >> P;
	strs.resize(P);
	int allsum = 0;
    for (int j = 0; j < P; j++) {
      cin >> strs[i];
      cars[i].pb(st_name[strs[i]]);
	  allsum += sts[st_name[str]].L;
    }
	if(allsum > D){
		continue;
	}
	for(int j = 0; j < P; j++){
		st_cnt[id]
	}
	for(int id : cars[i]){
		st_cnt[id]++;	
	}
  }
  for (int i = 0; i < I; i++) {
    vector <int> tmp;
	int totsz = 0;
    for (int j : it_in[i]) {
      if (st_cnt[j]){
		  totsz += (wei(st_cnt[j]));
		  tmp.pb(j);
		}
    }
    if (!tmp.size()) continue;
    Plan now(i);
	vector<pair<string, int>> vec;
    for (int j : tmp) {
		vec.push_back({st_id[j], ((i == 499) ? max(1 + (rand() % 100 <= 2), wei(st_cnt[j])) : wei(st_cnt[j]))});
    }
	for(auto [name, l] : vec){
		now.sts.push_back(name);
		now.len.push_back(l);
	}
    now.sze = now.sts.size();
    sol.pb(now);
  }
  cout << sol.size() << endl;
  for (Plan now : sol) {
    cout << now.id << endl;
    cout << now.sts.size() << endl;
    for (int i = 0; i < now.sze; i++) {
      cout << now.sts[i] << " " << now.len[i] << endl;
    }
  }
}

