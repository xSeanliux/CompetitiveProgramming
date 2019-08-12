#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10000;
int best[MAXN + 10][2]; //best[i][j] = the ith node not coloured, or coloured
int N, a, b;
vector<vector<int> >adj;

void dp(int root){

}

int main(){
    while(cin >> N){
        adj.clear();
        adj.reserve(N + 1);
        for(int i = 1; i < N; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cin >> a;
        if(a == 0){ //output


        } if(a == -1){ //output and return

        }
    }
}
