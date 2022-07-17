#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <map>
#include <iostream>
#define pb push_back
using namespace std;

int D, I, S, V, F;
struct Street {
  int B, E, L;
};
vector <Street> sts;        // street's information
map <string, int> st_name;  // street name
map <int, string> st_id;    // street id
vector <int> st_cnt;        // street used cnt
vector <vector<int>> it_in; // intersections indegree
vector <vector<int>> cars;  // car's goal

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
}

void output() {
  cout << sol.size() << endl;
  for (Plan now : sol) {
    cout << now.id << endl;
    cout << now.sts.size() << endl;
    for (int i = 0; i < now.sze; i++) {
      cout << now.sts[i] << " " << now.len[i] << endl;
    }
  }
}

signed main() {
    srand(time(0));
  cin >> D >> I >> S >> V >> F;
  init();
  for (int i = 0; i < S; i++) {
    auto &[B, E, L] = sts[i];
    string str;
    cin >> B >> E >> str >> L;
    it_in[E].pb(i);
    st_name[str] = i;
    st_id[i] = str;
  }
  for (int i = 0; i < V; i++) {
    int P;
    cin >> P;
    int time_sum = 0;
    for (int j = 0; j < P; j++) {
      string str;
      cin >> str;
      cars[i].pb(st_name[str]);
      if (j)
        time_sum += sts[st_name[str]].L;
    }
    if (time_sum <= D) {
      for (int j = 0; j+1 < P; j++) {
        st_cnt[cars[i][j]]++;
      }
    }
  }
  for (int i = 0; i < I; i++) {
    vector <int> tmp;
    for (int j : it_in[i]) {
      if (st_cnt[j]) tmp.pb(j);
    }
    if (!tmp.size()) continue;
    Plan now(i);
    for (int j : tmp) {
      now.sts.pb(st_id[j]);
      now.len.pb(1);
    }
    sort(now.sts.begin(), now.sts.end(), [&](const string a, const string b) {
      return st_cnt[st_name[a]] > st_cnt[st_name[b]];
    });
      random_shuffle(now.sts.begin(), now.sts.end());
    now.sze = now.sts.size();
    sol.pb(now);
  }
  output();
  return 0;
}

