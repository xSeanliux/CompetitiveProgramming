#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

struct Path{
    int s;
    int e;
    int wei;
};

vector< vector<Path> > adj;
int minDist[1000];
int T, n, m, a, b, w; //min: -(n * 1000 - 1)


int main(){
    cin >> T;
    while(T--){
        adj.clear();
        minDist[0] = 0;
        bool isPossible = false;
        priority_queue<int> toUpdate;
        cin >> n >> m;
        adj.resize(n);
        for(int i = 1 ; i < n; i++){
            minDist[i] = 214748;
        }
        long long int lim = 0;
        for(int i = 0 ; i < m; i++){
            scanf("%d %d %d", &a, &b, &w);
            Path p;
            p.s = a;
            p.e = b;
            p.wei = w;
            adj[a].push_back(p);
        }
        isPossible = false;
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                int L = adj[j].size();
                for(int k = 0 ; k < L; k++){
                    minDist[ adj[j][k].e ] = ˜min(minDist[ adj[j][k].e ], minDist[j] + adj[j][k].wei);
                }
            }
        }

        for(int i = 0 ; i < n; i++){
            int L = adj[i].size();
            for(int j = 0; j < L; j++){
                if(minDist[ adj[i][j].e ] > minDist[i] + adj[i][j].wei){
                    isPossible = true;
                }
            }
        }
        if(isPossible){
            cout << "possible" << endl;
        } else {
            cout << "not possible" << endl;
        }
    }
}
