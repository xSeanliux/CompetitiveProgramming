#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e6 + 10, L = 30;
vector<vector<int>> adj;

int N, K, a[maxN], ans = 0, p[maxN], stk[maxN], m = 0;


struct Node {
    Node *chi[2];
    int cnt;
    Node() {
        chi[0] = chi[1] = NULL;
        cnt = 0;
    }
};

struct Trie {
    Node *root;
    Trie() { root = new Node(); }
    void add(int x) {
        //cout << "adding " << x << endl;
        Node *cur = root;
        for(int i = L; i >= 0; i--) {
           int d = (x >> i) & 1; 
           //cout << d;
           if(!cur->chi[d]) cur->chi[d] = new Node();
           cur->cnt++;
           cur = cur->chi[d];
        }
        cur->cnt++;
        //cout << endl;
    }
    void del(int x) {
        Node *cur = root;
        for(int i = L; i >= 0; i--) {
           int d = (x >> i) & 1; 
           cur->cnt--;
           cur = cur->chi[d];
        }
        cur->cnt--;
    }
    int getMax(int x) {
        int r = 0;  
        Node *cur = root;
        for(int i = L; i >= 0; i--) {
            if((r | (1 << (i + 1)) - 1) <= ans) return -1;
            int d = (x >> i) & 1;
            if(cur->chi[d ^ 1] && cur->chi[d ^ 1]->cnt) {
                r += (1 << i);
                cur = cur->chi[d ^ 1];
            } else {
                cur = cur->chi[d];
            }
        }
        return r;
    }
} trie;



void dfs(int u = 1, int dep = 0) {
    a[u] ^= a[p[u]];
    if(u > 1) ans = max(ans, trie.getMax(a[u]));
    if(dep < K) ans = max(ans, a[u]);
    stk[m++] = u;
    int kth = (m > K ? stk[m - K - 1] : 0);
    trie.add(a[u]);
    if(kth) trie.del(a[kth]);
    for(int v : adj[u]) dfs(v, dep + 1);
    if(kth) trie.add(a[kth]);
    trie.del(a[u]);
    m--;
}



signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> K;
    adj = vector<vector<int>>(N + 1, vector<int>());
    for(int i = 1; i <= N; i++) cin >> a[i];
    for(int u = 2; u <= N; u++) {
        int v;
        cin >> v;
        p[u] = v;
        adj[v].push_back(u);
    }
    ans = a[1];
    dfs();
    cout << ans << '\n';
}




