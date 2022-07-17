#include <iostream>
#include <vector>
#include <string.h>
#include <array>
using namespace std;
const int AL = 26, maxN = 4e5 + 10;

vector<int> failAdj[maxN];
int s[maxN], e[maxN], pos[maxN];

struct aho_corasick {
  struct node {
    int p = 0;
    array<int, AL> nx;
    array<int, AL> kmp;
    int link = -1;
    char ch;
    node(char ch) : ch(ch) {
      fill(nx.begin(), nx.end(), -1);
      fill(kmp.begin(), kmp.end(), -1);
    }
    int& operator[](char c) {
      return nx[c - 'a'];
    }
    int& operator()(char c) {
      return kmp[c - 'a'];
    }
  };
  vector<node> trie;
  aho_corasick(): trie(1,'!') {}
  int add_string(const string &s) {
    int cr = 0;
    for(auto &c : s) {
      if(trie[cr][c] == -1) {
        trie[cr][c] = trie.size();
        trie.emplace_back(c);
        trie.back().p = cr;
      }
      cr = trie[cr][c];
    }
    return cr;
  }
  int go(int x, char c = '-') {
    if(c == '-') {
      if(trie[x].link != -1) return trie[x].link;
      if(x == 0 || trie[x].p == 0) trie[x].link = 0;
      else trie[x].link = go(go(trie[x].p), trie[x].ch);
      go(trie[x].link);
      return trie[x].link;
    }
    if(trie[x](c) != -1) return trie[x](c);
    if(trie[x][c] != -1) return trie[x](c) = trie[x][c];
    if(!x) return 0;
    return trie[x](c) = go(go(x), c);
  }
  void build() {
    for(int i = 0; i < trie.size(); i++) {
      go(i);
      failAdj[trie[i].link].push_back(i);
    }
  }
  int find(string s) {
    int cr = 0;
    for(auto &c : s) cr = go(cr, c);
    return cr;
  }
  int size() {
    return trie.size();
  }
  void disp(int u = 0, int dep = 0) {
    for(int i = 0; i < dep; i++) cout << "\t";
    cout << "Node " << u << ": " << trie[u].ch << ", link = " << trie[u].link << endl;
    for(char c = 'a'; c <= 'z'; c++) if(trie[u][c] > 0) disp(trie[u][c], dep + 1);
  }
} ahc;

int failpos = 0;
void failDFS(int u = 0) {
  s[u] = failpos++;
  for(int v : failAdj[u]) if(v != u) failDFS(v);
  e[u] = failpos;
}

struct BIT {
  int bit[maxN];
  BIT(){ fill(bit, bit + maxN, 0); }
  void modify(int p, int x) {
    if(!p) return;
    for(; p < maxN; p += (p & -p)) bit[p] += x;
  }
  int query(int p) {
    if(!p) return 0;
    int r = 0;
    for(; p; p -= (p & -p)) r += bit[p];
    return r;
  }
  int query(int l, int r) { //query [l, r]
    return query(r) - query(l - 1);
  }
} bit;

int ans[maxN], nodeidx[maxN];
string queryString[maxN];
char chars[maxN];

int N, M, songAdj[maxN][AL];
vector<int> hasQueries[maxN], songContain[maxN], nodeHas[maxN]; //contains the IDs of queries

int treeBelong[maxN], songcnt = 1;

int addLetter(int p, char c) {
  if(songAdj[p][c - 'a'] == -1) {
    fill(songAdj[songcnt], songAdj[songcnt] + 26, -1);
    songAdj[p][c - 'a'] = songcnt++;
  }
  return songAdj[p][c - 'a'];
}

void treeDFS(int treeNode = 0, int ahcNode = 0) {
  //update BIT
  //process queries 
  //recurse
  //revert BIT
  
  bit.modify(s[ahcNode], 1);
  for(int x : nodeHas[treeNode]){
    for(int idx : hasQueries[x]) {
      ans[idx] = bit.query(s[nodeidx[idx]], e[nodeidx[idx]] - 1);
      //cout << "ans[" << idx << "] = " << ans[idx] << endl;
    }
  }
  //cout << "OK" << endl;
  for(int i = 0; i < 26; i++) {
    if(songAdj[treeNode][i] == -1) continue;
    int v = songAdj[treeNode][i];
    //cout << "At " << treeNode << " "  << ahcNode << endl;
    //cout << "going to " << (i + 'a') << endl;
    treeDFS(v, ahc.go(ahcNode, (i + 'a')));
  }
  bit.modify(s[ahcNode], -1);
}

int main() {
  for(int i = 0; i < maxN; i++) for(int j = 0; j < AL; j++) songAdj[i][j] = -1;
  cin >> N;
  for(int i = 1; i <= N; i++){
    int t, p;
    cin >> t;
    if(t == 2) cin >> p;
    else p = 0;
    cin >> chars[i];
    treeBelong[i] = addLetter(treeBelong[p], chars[i]);
    nodeHas[treeBelong[i]].push_back(i);
  }
  cin >> M;
  for(int i = 0; i < M; i++) {
    int idx;
    cin >> idx >> queryString[i];
    hasQueries[idx].push_back(i);
    nodeidx[i] = ahc.add_string(queryString[i]);
  }
  ahc.build();
  //ahc.disp();
  failDFS();
  //start DFS?
  treeDFS();
  for(int i = 0; i < M; i++) cout << ans[i] << endl;
}