#include <iostream>
#include <string.h>
using namespace std;

int board[9][9];

string s1, s2;


void dfs(int y, int x, int step){
    //cout <<"running x = " << x << " , y = " << y << endl;
    if(y > 8 || x > 8 || x < 1 || y < 1) return;
    if(board[y][x] < step) return;
    board[y][x] = step;
    dfs(y + 2, x + 1, step+1);
    dfs(y + 2, x - 1, step+1);
    dfs(y - 2, x + 1, step+1);
    dfs(y - 2, x - 1, step+1);
    dfs(y + 1, x + 2, step+1);
    dfs(y + 1, x - 2, step+1);
    dfs(y - 1, x + 2, step+1);
    dfs(y - 1, x - 2, step+1);
}

int main(){
    while(cin >> s1 >> s2){
        for(int i = 1; i <= 8; i++){
            for(int j = 1; j <= 8; j++){
                board[i][j] = 1000;
            }
        }
        int startX, startY, endX, endY;
        startX = s1[0] - 'a' + 1;
        startY = s1[1] - '0';
        endX = s2[0] - 'a' + 1;
        endY = s2[1] - '0';
        board[startY][startX] = 0;
        dfs(startY, startX, 0);
        //printf("To get from %s to %s takes %d knight moves.\n", s1, s2, board[endY][endX]);
        cout << "To get from " << s1 << " to " << s2 << " takes "<< board[endY][endX] << " knight moves." << endl;
        }
}
