/*
#include <iostream>
#include <set>
#include <vector>
*/
#include<bits/stdc++.h>
#define lli long long int
using namespace std;

bool visited[100000], canReach;
vector<vector<lli> > adj;
lli n, q, x, K = 0, op, a, b;

void dfs(int currentNode){
    if(canReach) return;
    visited[currentNode] = true;
    for(int i = 0; i < adj[currentNode].size(); i++){
        if(!visited[adj[currentNode][i]]){
            if(adj[currentNode][i] == b){
                canReach = true;
                return;
            }
            dfs(adj[currentNode][i]);
        }
    }
}

int main(){
    cin >> n >> q >> x;
    for(int i = 0; i <= n; i++) adj.push_back(vector<lli>());
    while(q--){
        cin >> op >> a >> b;
        if(x){
            a ^= K;
            b ^= K;
        }
        if(op == 0){
            adj[a].push_back(b);
            adj[b].push_back(a);
        } else if(op == 1){
            adj[a].erase(find(adj[a].begin(), adj[a].end(), b));
            adj[b].erase(find(adj[b].begin(), adj[b].end(), a));
        } else {
            //cout << "Checking (" << a << ", " << b << ")" << endl;
            for(int i = 0; i <= n; i++) visited[i] = false;
            canReach = false;
            if(a == b){
                cout << "Y" << endl;
                K = a;
                continue;
            }
            dfs(a);
            if(canReach){
                cout << "Y" << endl;
                 K = a;
            } else {
                cout << "N" << endl;
                 K = b;
            }
            //cout << "K = " << K << endl;
        }

    }
}
