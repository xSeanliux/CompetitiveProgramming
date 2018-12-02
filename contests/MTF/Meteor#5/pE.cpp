#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, currentRoot = 1;
vector <int> childs[100005];
priority_queue <int> que;

int main(){
    int k;
    cin >> n;
    bool isRoot[n+1];
    for(int i = 1; i <= n; i++)
        isRoot[i] = true;
    for(int i = 1 ; i <= n; i++){
        isRoot[i] = 1;
        cin >> k;
        int t;
        for(int j = 0; j < k; j++){
            cin >> t;
            childs[i].push_back(t);
            isRoot[t] = false;
        }
    }
    for(int i = 1; i <= n; i++)
        if(isRoot[i]){
            currentRoot = i;
            break;
        }
    que.push(currentRoot);
    while(!que.empty()){
        int top = que.top();
        int l = childs[top].size();
        for(int i = 0 ; i < l; i++){
            que.push(childs[top][i]);
        }
        cout << top << " ";
        que.pop();
    }

}
