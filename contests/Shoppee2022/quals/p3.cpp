#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <set>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5;

int N, arr[maxN * 2], T, spos, colour[maxN], rp[maxN];
vector<int> adj[maxN];
bool seen[maxN];

void addEdge(int u, int v) {
    //cout << "adding " << u << " " << v << endl;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfs(int u, int col) {
    colour[u] = col;
    bool f = true;
    for(int v : adj[u]) {
        if(colour[v] == col) return false;
        if(colour[v] == -1)  f &= dfs(v, col ^ 1);
    }
    return f;
}

inline void solve() {
    cin >> N;
    fill(seen, seen + N + 1, 0);
    for(int i = 0; i <= N; i++) adj[i].clear();
    for(int i = 0; i < 2 * N; i++) cin >> arr[i];
    fill(seen, seen + N + 1, 0);
    for(int i = 0; i < 2 * N; i++) {
        if(seen[arr[i]]) {
            rp[arr[i]] = i;
        } else {
            seen[arr[i]] = 1;
        }
    }
    set<pii> st = set<pii>(); //rightedge, arr value
    fill(seen, seen + N + 1, 0);
    for(int i = 0; i < 2 * N; i++) {
        if(seen[arr[i]]) {
            st.erase(pii{i, arr[i]});
        } else {
            if(st.size()) {
                auto [re, va] = *st.begin(); 
                if(re < rp[arr[i]]) addEdge(arr[i], va);
            }
            seen[arr[i]] = 1;
            st.insert(pii{rp[arr[i]], arr[i]});
        }
    }
    reverse(arr, arr + 2 * N);
    st = set<pii>(); //rightedge, arr value
    fill(seen, seen + N + 1, 0);
    for(int i = 0; i < 2 * N; i++) {
        if(seen[arr[i]]) {
            rp[arr[i]] = i;
        } else {
            seen[arr[i]] = 1;
        }
    }
    fill(seen, seen + N + 1, 0);
    for(int i = 0; i < 2 * N; i++) {
        if(seen[arr[i]]) {
            st.erase(pii{i, arr[i]});
        } else {
            if(st.size()) {
                auto [re, va] = *st.begin(); 
                if(re < rp[arr[i]]) addEdge(arr[i], va);
            }
            seen[arr[i]] = 1;
            st.insert(pii{rp[arr[i]], arr[i]});
        }
    }
    fill(colour, colour + N + 1, -1);
    bool f = true;
    for(int i = 1; i <= N; i++) if(colour[i] == -1) f &= dfs(i, 0);
    if(!f) {
        cout << "no\n";
        return;
    }
    //for(int i = 1; i <= N; i++) cout << colour[i] << " "; cout << endl;
    stack<int> stk1 = stack<int>(), stk2 = stack<int>();
    fill(seen, seen + N + 1, 0);
    for(int i = 0; i < 2 * N; i++) {
        if(colour[arr[i]]) {
            if(seen[arr[i]]) {
                while(stk1.size() && stk1.top() != arr[i]) {
                    stk1.pop();
                }
                if(!stk1.size()) {
                    cout << "no\n"; 
                    return;
                }
                stk1.pop();
            } else {
                stk1.push(arr[i]);
                seen[arr[i]] = 1;
            }
        } else {
            if(seen[arr[i]]) {
                while(stk2.size() && stk2.top() != arr[i]) {
                    stk2.pop();
                }
                if(!stk2.size()) {
                    cout << "no\n"; 
                    return;
                }
                stk2.pop();
            } else {
                stk2.push(arr[i]);
                seen[arr[i]] = 1;
            }
        }
    }
    cout << "yes\n";
    return;
}

int main() {
    ericxiao; 
    cin >> T;
    while(T--) {
        solve();
    }
}
