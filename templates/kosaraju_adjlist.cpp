#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;


vector <vector<int> > adj;
vector <vector<int> > rev;
vector <int> ord; //dfs order
bool visited[MAX];
int N, q, a, b;

void dfs1(int ind){
    //cout << "now: dfs(" << ind << ")" << endl;
    int S = adj[ind].size();
    for(int i = 0 ; i < S; i++){
        if(!visited[ adj[ind][i] ]){
            ord.push_back(adj[ind][i]);
            visited[ adj[ind][i] ] = true;
            dfs1(adj[ind][i]);
            ord.push_back(adj[ind][i]);
        }
    }
}


void dfs2(int ind){
    int S = rev[ind].size();
    for(int i = 0 ; i < S; i++){
        if(!visited[ rev[ind][i] ]){
            visited[ rev[ind][i] ] = true;
            cout << " " << rev[ind][i];
            dfs2(rev[ind][i]);
        }
    }
}

int main(){
    cin >> N >> q;
    adj.resize(N + 1);
    rev.resize(N + 1);
    //cout << "A" << endl;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    //cout << "A" << endl;
    //dfs1
    for(int i = 1 ; i <= N; i++){
        if(!visited[i]){
            visited[i] = true;
            ord.push_back(i);
            dfs1(i);
            ord.push_back(i);
        }
    }

    for(int i = 0 ; i < ord.size(); i++){
        cout << ord[i] << " ";
    }
    cout << endl << endl;

    for(int i = 1 ; i <= N; i++){
        visited[i] = false;
    }

    int l = ord.size();
    for(int i = l-1; i >= 0; i--){
        if(!visited[ ord[i] ] ){
            cout << ord[i];
            visited[ ord[i] ] = true;
            dfs2(ord[i]);
            cout << endl;
        }
    }
}
