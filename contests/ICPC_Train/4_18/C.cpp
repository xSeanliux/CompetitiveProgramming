#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const int maxN = 5e5 + 10, W = 30;

int N, M, cnt = 1, curAt = 0;
char ch[maxN];
string queries[maxN];
vector<int> song[maxN], toProcess[maxN], failTree[maxN];
int l[maxN], r[maxN], ord[maxN];

struct BIT {
    int bit[maxN];
    BIT(){}
    void modify(int p, int x) {
        for(; p < maxN; p += (p & -p)) bit[p] += x;
    }
    int query(int p) {
        int r = 0;
        for(; p; p -= (p & -p)) r += bit[p];
        return x;
    }
} bit;

struct Node {
    int go[W]; 
    int fail, pred;
    char c;
    vector<int> endIndex;
    Node(){
        endIndex = vector<int>();
        fill(go, go + W, 0);
        fail = 0;
        pred = 0;
        c = 0;
    }
} ac[maxN];

int newNode(int pred, char c) {
    ac[cur].pred = pred;
    ac[cur].c = c;
    return cur++;
}

void addString(string s, int idx) {
    int cur = 0;  //root node
    for(char c : s) {
        if(!ac[cur].go[c - 'a']) {
            ac[cur].go[c - 'a'] = newNode(cur, c);
        }
        cur = ac[cur].go[c - 'a'];
    }
    ac[cur].endIndex.push_back(idx);
}

void buildAC() {
    for(int i = 1; i < cnt; i++) {
        int q = ac[ac[i].pred].fail;
        while(q && !ac[q].go[ac[i].c]) q = ac[q].fail;
        ac[i].fail = ac[q].go[ac[i].c];

        failTree[ac[i].fail].push_back(i);
        failTree[i].push_back(ac[i].fail);

        for(int c = 0; c < 26; c++) {
            ac[i].go[c] = ac[i].go[c] ? ac[i].go[c] : ac[ac[i].fail].go[c];
        }
    }
}

void runDFS(int u = 0) {
    if(u) {
       curAt = ac[curAt].go[ch[u]];
       modify(curAt, 1);
    }
    for(int x : toProcess[u]) { //do something
        ans[x] = query(x);  //todo: modify and query
    }
    for(int v : song[u]) {
        runDFS(v); 
    }
    if(u) modify(curAt, -1);
}

int main() {
    cin >> N; 
    for(int i = 1, t, c, j; i <= N; i++) {
        cin >> t;
        if(t == 1) {
            cin >> ch[i];
            song[0].push_back(i);
        } else {
            cin >> j >> ch[i];
            song[j].push_back(i);
        }
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        int j;
        cin >> j >> queries[i];
        toProcess[j].push_back(i); 
        addString(queries[i], i);
    }
    buildAC();
    runDFS();
}

