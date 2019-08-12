#include "testlib.h"
using namespace std;

int abs(int x){
    return (x > 0) ? x : -x;
}

int main(int argc, char * argv[]){
    setName("compares two signed integers");
    registerTestlibCmd(argc, argv);
    int N = inf.readInt();
    bool visited[N][N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                visited[i][j][k] = false;
            }
        }
    }
    int x, y, z, lx, ly, lz;
    for(int i = 0; i < N*N*N; i++){
        x = ouf.readInt();
        y = ouf.readInt();
        z = ouf.readInt();
        if(!i){
            if(x != 0 || y != 0 || z != 0){
                quitf(_wa, "Starting coordinates should be zero");
            }
        } else {
            if(x < 0 || y < 0 || z < 0 || x >= N || y >= N || z >= N){
                quitf(_wa, "Index out of bounds");
            }
            if(( abs(x - lx) + abs(y - ly) + abs(z - lz) ) != 1){
                quitf(_wa, "Invalid move from %d %d %d", lx, ly, lz);
            }
            if(visited[x][y][z]){
                quitf(_wa, "Already visited: %d %d %d", x, y, z);
            }
        }
        visited[x][y][z] = true;
        swap(x, lx);
        swap(y, ly);
        swap(z, lz);
    }
    quitf(_ok, "Correct Path.");
}
