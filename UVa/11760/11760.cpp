#include <iostream>
#include
using namespace std;
int H, W, C, x, y, c = 0;


bool check(int y, int x){
    if(x < 0 || y < 0 || x >= W || y >= C) return false;
    if(!isGood[y][x]) return false;
    return true;
}


int main(){
    while(cin >> H >> W >> C){
        if(!(H | W | C)) return 0;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++)
                isGood[i][j] = true;
        }
        for(int i = 0; i < C; i++){
            cin >> y >> x;
            for(int j = 0; j < H; j++){
                isGood[j][x] = false;
            }
            for(int j = 0; j < W; j++){
                isGood[y][j] = false;
            }
        }
        cin >> y >> x;
        printf("Case %d: ", ++c);
        cout << ((check(y, x) || check(y + 1, x) || check(y - 1, x) || check(y, x + 1) || check(y, x - 1)) ? "Escaped again! More 2D grid problems!" : "Party time! Let's find a restaurant!") << endl;
    }
}
