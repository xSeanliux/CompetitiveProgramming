#include <iostream>
#include <string.h>
using namespace std;

int mX, mY, x, y;
string com;
bool isFinished;
char grid[50 + 5][50 + 5], dir;

void moveForward(){
    switch (dir){
    case 'N':
        y++;
        break;
    case 'E':
        x++;
        break;
    case 'S':
        y--;
        break;
    case 'W':
        x--;
        break;
    }
}

void moveBackward(){
    switch (dir){
    case 'N':
        y--;
        break;
    case 'E':
        x--;
        break;
    case 'S':
        y++;
        break;
    case 'W':
        x++;
        break;
    }
}

void turnRight(){
    switch(dir){
    case 'N':
        dir = 'E';
        break;
    case 'E':
        dir = 'S';
        break;
    case 'S':
        dir = 'W';
        break;
    case 'W':
        dir = 'N';
        break;
    }
}

void turnLeft(){
    switch(dir){
    case 'N':
        dir = 'W';
        break;
    case 'W':
        dir = 'S';
        break;
    case 'S':
        dir = 'E';
        break;
    case 'E':
        dir = 'N';
        break;
    }
}

bool isDead(){
    return (x*y < 0 || y > mY || x > mX);
}

void go(char c){
    if(c == 'F'){
        moveForward();
    } else if(c == 'R') {
        turnRight();
    } else {
        turnLeft();
    }
}

int main(){
    cin >> mX >> mY;
    for(int i = 0 ; i < mX; i++){
        for(int j = 0 ; j < mY; j++){
            grid[i][j] = ' ';
        }
    }
    while(cin >> x >> y >> dir){
        isFinished = false;
        cin >> com;
        int l = com.length();
        for(int i = 0 ; i < l; i++){
            if(grid[y][x] != 'X')
                go(com[i]);
            else {
                go(com[i]);
                if(x*y < 0 || y > mY || x > mX){
                    moveBackward();
                }
            }
            if(x*y < 0 || y > mY || x > mX){
                moveBackward();
                grid[y][x] = 'X';
                isFinished = true;
                break;
            }
        }
        printf("%d %d %c", x, y, dir);
        if(isFinished) printf(" LOST");
        printf("\n");
    }
}
