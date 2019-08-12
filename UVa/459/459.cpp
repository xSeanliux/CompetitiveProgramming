#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

string s;
vector<vector<int> > adj;
int cases, con;
bool visited[30], hasP = true;;
char maxChar;

void dfs(int i){
    //cout << "Running dfs(" << i << ")" << endl;
    visited[i] = true;
    for(auto k : adj[i]) if(!visited[k]) dfs(k);
}


int main(){
    cin >> cases;
    while(cases--){
        adj.clear();
        con = 0;
        cin >> maxChar;
        for(int i = 0; i <= maxChar - 'A'; i++){
            adj.push_back(vector<int>());
            visited[i] = false;
        }
        getline(cin, s);
        getline(cin, s);
        while(s != ""){
            adj[s[0] - 'A'].push_back(s[1] - 'A');
            adj[s[1] - 'A'].push_back(s[0] - 'A');
            if(!getline(cin, s)) break;
        }
        for(int i = 0; i <= maxChar - 'A'; i++){
            if(!visited[i]){
                dfs(i);
                con++;
                //cout << endl;
            }
        }
        if(hasP) hasP = false;
        else cout << endl;
        cout << con << endl;
    }
}
