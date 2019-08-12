#include <iostream>
#include <map>
using namespace std;

int x, y, locs[999 + 10][2], k, inx, iny;

bool canMove(int x, int y){
    if(x < 1 || y < 1 || x > 999 || y > 999) return false;
    for(int i = 1; i <= 666; i++)
        if(locs[i][0] == x && locs[i][1] == y) return false;
    return true;
}

int main(){
    scanf("%d%d", &x, &y);
    for(int i = 1; i <= 666; i++){
        scanf("%d%d", &locs[i][0], &locs[i][1]);
    }
    for(int r = 0; r < 2000; r++){ //at most 2000 moves
        if(k == -1 && inx == -1 && iny == -1) return 0;
        else{
            locs[k][0] = inx;
            locs[k][1] = iny;
        }
        int dx = rand() % 2 * 2 - 1, dy = rand() % 2 * 2 - 1;
        while(!canMove(x + dx, y + dy)){
            dx = rand() % 2 * 2 - 1, dy = rand() % 2 * 2 - 1;
        }
        x += dx;
        y += dy;
        printf("%d %d\n", x, y);
        fflush(stdout);
        scanf("%d%d%d", &k, &inx, &iny);
    }
}
