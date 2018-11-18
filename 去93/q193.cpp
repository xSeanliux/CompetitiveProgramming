#include <iostream>
using namespace std;
int N, blackNodes;
int n, k;
int map[105][105];
bool visited[105];
void dfs(int currentNode, char colour, int iteration){
    if(iteration == n) return;
    if(colour = 'b'){
        blackNodes++;
        for(int i = 0; i < n; i++){
           if(map[i][currentNode] == 1 && visited[i]){
                map[i][currentNode] = 2;
                map[currentNode][i] = 2;
                visited[i] = false;
                dfs(i, 'w', iteration++);
           }
        }
    } else {
        for(int i = 0; i < n; i++){
           if(map[i][currentNode] == 1 && visited[i]){
                map[i][currentNode] = 2;
                map[currentNode][i] = 2;
                visited[i] = false;
                dfs(i, 'b', iteration++);
           }
        }
    }
}

int main(){
    while(cin >> N){

        for(int i = 0 ; i < N; i++){
            cin >> n >> k;
            blackNodes = 0;
            int from, to;
            for(int i = 1; i <= n; i++){
                visited[i]  =false;
                for(int j = 1; j <= n; j++){
                    map[i][j] = 0;
                }
            }
            for(int j = 0; j < k; j++){
                cin >> from >> to;
                map[from][to] = 1;
                map[to][from] = 1;
            }

            dfs(1, 'b', 0);
            cout << blackNodes << endl;

        }
    }
}
