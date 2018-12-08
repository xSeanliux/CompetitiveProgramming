#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int b, N, e, numToCheck, root;



int main(){
    while(cin >> N){
        if(!N) return 0;
        vector <int> adj[N + 1];
        bool isReachable[N + 1];

        while(cin >> b){ //currentNode = b
            if(!b) break;
            while(cin >> e){
                if(!e) break;
                adj[b].push_back(e);
            }
        }
        cin >> numToCheck;
        for(int i = 0 ; i < numToCheck; i++){
            cin >> root;
            queue <int> que;
            memset(isReachable, false, N + 1);
            que.push(root);
            while(!que.empty()){
                int top = que.front();
                int l = adj[top].size();
                for(int j = 0; j < l; j++){
                    if(!isReachable[adj[top][j]]){
                        isReachable[adj[top][j]] = true;
                        que.push(adj[top][j]);
                    }
                }
                que.pop();
            }
            vector <int> ans;
            for(int j = 1 ; j <= N; j++)
                if(!isReachable[j])
                    ans.push_back(j);
            cout << ans.size();
            for(int j = 0; j < ans.size(); j++)
                cout << " " << ans[j];
            cout << endl;
        }
    }
}
