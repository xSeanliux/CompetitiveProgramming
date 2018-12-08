#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAX 100005
using namespace std;


vector <vector<int> > adj;
vector <vector<int> > rev;
vector <int> disjoint;
vector <int> ord; //dfs order
bool visited[MAX], degiszero[MAX], isIn[MAX];
long long int C, N, q, a, b;



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


void dfs2(int ind, int ori){
    int S = rev[ind].size();
    for(int i = 0 ; i < S; i++){
        if(!visited[ rev[ind][i] ]){
            visited[ rev[ind][i] ] = true;
            disjoint[ rev[ind][i] ] = ori;
            //cout << " " << rev[ind][i];
            //cout << rev[ind][i] << " has ancestor: " << ori << endl;
            //remove the link
            //vector<int>::iterator it = find(adj[ rev[ind][i] ].begin(), adj[ rev[ind][i] ].end(), ori);
            //if (it != adj[ rev[ind][i] ].end()) // == myVector.end() means the element was not found
            //  adj[ rev[ind][i] ].erase(it);
            //
            dfs2(rev[ind][i], ori);
        }
    }
}

int main(){
    cin >> C;
    while(C--){
        scanf("%lld %lld", &N, &q);
        adj.clear();
        rev.clear();
        disjoint.clear();
        ord.clear();
        adj.resize(N + 1);
        rev.resize(N + 1);
        disjoint.resize(N + 1);
        memset (degiszero,true,sizeof(degiszero));
        memset (visited,false,sizeof(visited));
        memset (isIn,false,sizeof(isIn));
        disjoint.resize(N + 1);
        for(int i = 0; i < q; i++){
            scanf("%lld %lld", &a, &b);
            adj[a].push_back(b);
            rev[b].push_back(a);
            //isIn[a] = isIn[b] = true;
        }
        //dfs1
        for(int i = 1 ; i <= N; i++){
            disjoint[i] = i;
            if(!visited[i]){
                visited[i] = true;
                ord.push_back(i);
                dfs1(i);
                ord.push_back(i);
            }
        }


        memset (visited,false, sizeof(visited));

        for(int i = 1 ; i <= N; i++){
            visited[i] = false;
        }

        int l = ord.size();
        for(int i = l-1; i >= 0; i--){
            if(!visited[ ord[i] ] ){
                visited[ ord[i] ] = true;
                dfs2(ord[i], ord[i]);
            }
        }
        int L, ans = 0;
        for(int i = 1; i <= N; i++){
            L = adj[i].size();
            for(int j = 0; j < L; j++){
                if(disjoint[i] != disjoint[ adj[i][j] ])
                    degiszero[ disjoint[ adj[i][j] ] ] = false;
            }
        }

        for(int i = 1; i <= N; i++){
            if(disjoint[i] == i && degiszero[i]){
                ans++;
                //cout << "i: " << i << ", ances: " << disjoint[i] << ", deg zero? " << degiszero[i] << endl;
            }
        }
        cout << ans << endl;
    }

}
