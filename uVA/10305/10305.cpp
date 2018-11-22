#include <iostream>
using namespace std;


int conns[101], order[101], N, M, a, b;
bool adj[101][101], isAvailable[101];
int main(){
    while(cin >> N >> M){
        if(!N && !M)
            return 0;
        for(int i = 1; i <= N; i++){
            conns[i] = 0;
            isAvailable[i] = true;
            for(int j = 1; j <= N; j++){
                adj[i][j] = false;
            }
        }
        for(int i = 0 ; i < M; i++){
            cin >> a >> b;
            if(!adj[a][b])
                conns[b]++;
            adj[a][b] = true;
        }
        bool canFind = true, hasFound, hasPrinted = false;
        while(canFind){
            hasFound = false;
            for(int i = 1; i <= N; i++){
                if(!conns[i] && isAvailable[i]){
                    if(hasPrinted)
                        cout << " ";
                    else
                        hasPrinted = true;
                    cout << i;
                    for(int j = 1; j <= N; j++){
                        conns[j] -= adj[i][j];
                    }
                    hasFound = true;
                    isAvailable[i] = false;
                } else if(i == N && !hasFound){
                    canFind = false;
                    break;
                }
            }
        }
        cout << endl;
    }
}
