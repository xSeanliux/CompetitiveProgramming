#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int q, n, dsu[(int)(2e5 + 100)], sz[(int)(2e5 + 100)];

void init(){
    iota(dsu, dsu + n + 1, 0);
    for(int i = 0; i <= n; i++) sz[i] = 1;
}

void Flat(int x){
    if(x == dsu[x]) return;
    Flat(dsu[x]);
    sz[x] = sz[dsu[x]];
    dsu[x] = dsu[dsu[x]];
}

void Merge(int a, int b){
    Flat(a); Flat(b);
    if(dsu[a] == dsu[b]) return;
    sz[b] += sz[a];
    dsu[dsu[a]] = dsu[b];
}

vector<int> perm;
vector<bool> vis;

int main(){
    cin >> q;
    while(q--){
        cin >> n;
        vis.resize(n + 1);
        perm.resize(n + 1);
        init();
        for(int i = 1; i <= n; i++){
            cin >> perm[i];
            vis[i] = false;
        }
        int t;
        for(int i = 1; i <= n; i++){
            t = i;
            while(!vis[t]){
                vis[t] = true;
                Merge(t, i);
                t = perm[t];
            }
        }
        for(int i = 1; i <= n; i++){
            Flat(i);
            cout << sz[i] << " \n"[i==n];
        }
    }
}


