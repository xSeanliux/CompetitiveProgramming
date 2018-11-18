#include <iostream>
using namespace std;

int M, N, t;

int maze[1000][1000];

int main(){
    cin << t;
    for(int as = 0; as < t; as++){
        cin >> M >> N;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N ; j++){
                cin >> maze[i][j];
            }
        }
        int solMaze[M][N];
        for(int i = 0; i < M; i++){
            solMaze[i][0] = maze[i][0];
        }
        for(int i = 0; i < N; i++){
            solMaze[0][i] = maze[0][i];
        }
        for(int i = 1; i < M; i++){
            for(int j = 1; j < N ; j++){
                solMaze[i][j] = maze[i][j] + min(solMaze[i-1][j], solMaze[i][j-1]);
            }
        }
    }

}
