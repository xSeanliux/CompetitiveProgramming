#include <iostream>
#include <string.h>
#include <map>
#include <vector>
using namespace std;

map<string , int> ind;
vector<vector<string> > adj;
int deg[105], N, M, cc = 0;
bool visited[105];
string s, e, drinks[105];

int main(){
    while(cin >> N){
        memset(deg, 0, N);
        memset(visited, false, N);
        adj.clear();
        adj.resize(N);
        for(int i = 0 ; i < N; i++){
            cin >> drinks[i];
            ind.insert(pair<string, int>(drinks[i], i));
        }
        cin >> M;
        for(int i = 0; i < M; i++){
            cin >> s >> e;
            adj[ind[s]].push_back(e);
            deg[ind[e]]++;
        }
        int outputDrinks = 0;
        printf("Case #%d: Dilbert should drink beverages in this order:", ++cc);
        while(outputDrinks < N){
            for(int i = 0 ; i < N; i++){
                if(!deg[i] && !visited[i]){
                    cout << " " << drinks[i];
                    visited[i] = true;
                    int L = adj[i].size();
                    for(int j = 0 ; j < L; j++){
                        deg[ind[adj[i][j]]]--;
                    }
                    outputDrinks++;
                    break;
                }
            }
        }
        cout << "." << endl << endl;
    }
}

