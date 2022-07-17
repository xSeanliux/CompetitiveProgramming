#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <queue>
#define F first
#define S second
#define ll long long int
using namespace std;

const int maxN = 1e5 + 326;
vector<int> vec[maxN], ord, lisan;
multiset<int> adj[maxN * 3];
map<ll, queue<int>> mp;
map<ll, int> lc;

void addEdge(int u, int v) {
    adj[u].insert(v);
    adj[v].insert(u);
}

inline void run(int s) {
    stack<int> stk = stack<int>();
    stk.push(s);
    while(stk.size()) {
        int u = stk.top(); 
        if(!adj[u].size()) {
            ord.push_back(u); 
            stk.pop();
        } else {
            int v = *adj[u].begin();
            adj[v].erase(adj[v].find(u));
            adj[u].erase(adj[u].find(v));
            stk.push(v);
        }
    }
};


signed main() {
    int M, N;
    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> N;
        vec[i].resize(N);
        for(int j = 0; j < N; j++) {
            cin >> vec[i][j];
            lisan.push_back(vec[i][j]);
        }
    }
    sort(lisan.begin(), lisan.end());
    int sz = unique(lisan.begin(), lisan.end()) - lisan.begin();
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < (int)vec[i].size(); j++) {
            vec[i][j] = lower_bound(lisan.begin(), lisan.begin() + sz, vec[i][j]) - lisan.begin();
            addEdge(i, vec[i][j] + maxN);
        }
    }
    vector<int>().swap(lisan);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < (int)vec[i].size(); j++) {
            if(!mp.count((ll)i * maxN * 2 + vec[i][j])) 
                mp[(ll)i * maxN * 2 + vec[i][j]] = queue<int>();
            mp[(ll)i * maxN * 2 + vec[i][j]].push(j);
        }
    }
    for(int i = 0; i < 3 * maxN; i++) if(adj[i].size() % 2) { //no euler circuit
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < M; i++) if(adj[i].size()) run(i);
    /*
    cout << "ORD: " << endl;
    for(int x : ord) {
        if(x >= maxN) {
            cout << "N" << (x - maxN) << endl;
        } else {
            cout << "A" << x << endl;
        }
    }
    cout << "|ord| = " << ord.size() << endl;
    cout << endl;
    */
    int u, v;
    for(int i = 0; i < (int)(ord.size()) - 1; i++) {
        u = ord[i], v = ord[i + 1];
        //cout << "u = " << u << ", v = " << v << endl;
        if(u < maxN) { //give to L
            v -= maxN;
            ll id = (ll)u * maxN * 2 + v;
            if(!lc.count(id)) lc[id] = 0;
            lc[id]++;
        }   
    }
    cout << "YES" << endl;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < (int)vec[i].size(); j++) {
            if(lc[(ll)i * maxN * 2 + vec[i][j]]) {
                cout << "L";
                lc[(ll)i * maxN * 2 + vec[i][j]]--;
            } else cout << "R";
        }
        cout << endl;
    }
}
