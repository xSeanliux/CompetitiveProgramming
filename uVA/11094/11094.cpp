#include <iostream>
using namespace std;

int most = 0, current = 0, H, W, xAt, yAt;
char M[25][25];
bool hasWater;
char land, water;

void dfs(int y, int x){
    if(x < 0) x += W;
    if(x >= W) x -= W;
    if(y >= H || y < 0 || M[y][x] != land){
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
    while(cin >> H >> W){
        if(!W && !H) return 0;
        most = 0;
        hasWater = false;
        for(int i = 0 ; i < H; i++)
            for(int j = 0 ; j < W; j++)
                cin >> M[i][j];
        cin >> yAt >> xAt;
        land = M[yAt][xAt];
        //cout << "LAND: " << land << endl;
        dfs(yAt, xAt);
        for(int i = 0 ; i < H; i++)
            for(int j = 0 ; j < W; j++){
                if(M[i][j] != land && !hasWater) { hasWater= true;}
                current = 0;
                dfs(i, j);
                if(current > most) most = current;
            }
        cout << most << endl;

    }
}
