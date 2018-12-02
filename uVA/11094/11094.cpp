#include <iostream>
using namespace std;

int most = 0, current = 0, H, W, xAt, yAt;
char M[25][25];
char land, water;

void dfs(int y, int x){
    if(y >= H || x >= W || y < 0 || x < 0 || M[y][x] != land){
        return;
    }
    current++;
    M[y][x] = water;
    dfs(y + 1, x);
    dfs(y - 1, x);
    dfs(y, x + 1);
    dfs(y, x - 1);
}


int main(){
    while(cin >> W >> H){
        if(!W && !H) return 0;
        for(int i = 0 ; i < W; i++)
            for(int j = 0 ; j < H; j++)
                cin >> M[i][j];
        cin >> xAt >> yAt;
        land = M[yAt][xAt];
        dfs(yAt, xAt);
        for(int i = 0 ; i < W; i++)
            for(int j = 0 ; j < H; j++){
                if(M[i][j] != land) water = M[i][j];
                current = 0;
                dfs(i, j);
                if(current > most) most = current;
            }
        cout << most << endl;

    }
}
