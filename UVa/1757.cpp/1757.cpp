#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

map<char, set<char> > arr;
map<char, vector<char> > adj;

int n, m;
string a, b;
char c1, c2;

void dfs(char c, char currentChar){
    if(arr[c].count(currentChar)) return;
    arr[c].insert(currentChar);
    for(char ch : adj[currentChar]) dfs(c, ch);
}

bool canTransform(string a, string b){
    if(a.length() != b.length()) return false;
    for(int i = 0; i < a.length(); i++){
        if(!(arr[a[i]].count(b[i]))) return false;
    }
    return true;
}

int main(){
    while(cin >> n >> m){
        adj.clear(); arr.clear();
        for(int i = 0; i < n; i++){
            cin >> c1 >> c2;
            adj[c1].push_back(c2);
        }
        for(char c = 'a'; c <= 'z'; c++){
            dfs(c, c);
        }
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            if(canTransform(a, b)) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
}
