#include <iostream>
#include <vector>
#include <string.h>
#include <map>
using namespace std;

map <string, int> sToInt;
map <int, string> intToS;
vector <vector<int> > adj, adjrev;
vector <int> ord;
bool visited[30], flag;
string name1, name2;
int totalNames, calls, C = 0;

void dfs(int ind){
    if(visited[ind]) return;
    visited[ind] = true;
    ord.push_back(ind);
    int l = adj[ind].size();
    //cout << intToS[ind] << " has " << l << " neighbours" << endl;
    for(int i = 0 ; i < l; i++){
        //cout << "going to id = " << adj[ind][i] << " = " << intToS[adj[ind][i]] << endl;
        dfs(adj[ind][i]);
    }
    ord.push_back(ind);
}

void dfs2(int ind){
    if(visited[ind]) return;
    visited[ind] = true;
    if(!flag)
        flag = true;
    else
        cout << ", ";
    cout << intToS[ind];
    int l = adjrev[ind].size();
    for(int i = 0 ; i < l; i++){
        dfs2(adjrev[ind][i]);
    }
}


int main(){

    while(cin >> totalNames >> calls){
        if(!totalNames && !calls) return 0;
        if(C)
            cout << endl;
        sToInt.clear();
        intToS.clear();
        ord.clear();
        adj.clear();
        adjrev.clear();
        adj.resize(totalNames);
        adjrev.resize(totalNames);
        printf("Calling circles for data set %d:\n", ++C);
        //printf("Data: size of adj: %d, size of rev: %d\n", sToInt.size(), intToS.size());
        for(int i = 0 ; i < calls; i++){
            cin >> name1 >> name2;
            if(!sToInt.count(name1)){
                sToInt.insert(pair<string, int>(name1, sToInt.size()));
                intToS.insert(pair<int, string>(intToS.size(), name1));
                //cout << name1 << " has id" << sToInt.size() - 1 << " = " << intToS.size() - 1 << endl;
            }
            if(!sToInt.count(name2)){
                sToInt.insert(pair<string, int>(name2, sToInt.size()));
                intToS.insert(pair<int, string>(intToS.size(), name2));
                //cout << name2 << " has id" << sToInt.size() - 1 << " = " << intToS.size() - 1 << endl;
            }
            adj[sToInt[name1]].push_back(sToInt[name2]);
            adjrev[sToInt[name2]].push_back(sToInt[name1]);
        }
        //now run dfs
        memset(visited, false, totalNames);
        for(int i = 0 ; i < totalNames; i++){
            if(!visited[i])
                dfs(i);
        }
        /*
        cout << "ORD: " << endl;
        for(int i = 0 ; i < ord.size(); i++){
            cout << intToS[ord[i]] << " ";
        }
        cout << "EOR" << endl << endl;
        */
        //second time dfs
        memset(visited, false, totalNames);
        for(int i = ord.size() - 1 ; i >= 0; i--){
            if(!visited[ord[i]]){
                flag = false;
                dfs2(ord[i]);
                cout << endl;
            }
        }
    }
}
