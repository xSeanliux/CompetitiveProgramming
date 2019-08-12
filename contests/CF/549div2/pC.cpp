#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > childs;
vector<int> resp;
vector<int> toDel;
int N, p, c, rootAt, cnt = 0;

bool dfs(int currentNode){
    //cout << "dfs(" << currentNode << ")" << endl;
    cnt++;
    if(childs[currentNode].size() == 0){
        if(resp[currentNode]){
            toDel.push_back(currentNode);
            return true;
        }
        return false;
    } else {
        bool canDo = true;
        for(int node : childs[currentNode]){
            if(!dfs(node)) canDo = false;
        }
        if(canDo){
            toDel.push_back(currentNode);
            return true;
        }
        return false;
    }
}


int main(){
    cin >> N;
    childs.reserve(N + 2);
    resp.reserve(N + 2);
    resp.clear();
    toDel.clear();
    for(int i = 1; i <= N; i++) childs[i].clear();
    for(int i = 1; i <= N; i++){
        cin >> p >> c;
        if(p == -1){
            rootAt = i;
        } else {
            resp[i] = c;
            childs[p].push_back(i);
        }
    }
    dfs(rootAt);

    if(toDel.empty()){
        cout << -1 << endl;
        return 0;
    }
    sort(toDel.begin(), toDel.end());
    cout << toDel[0];
    for(int i = 1; i < toDel.size(); i++) cout << " " << toDel[i];
    cout << endl;
}
