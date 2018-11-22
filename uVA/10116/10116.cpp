#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int h, w, x, y, steps;
char maze[10 + 5][10 + 5];
int visited[15][15];

int main(){
    while(cin >> h >> w >> x){
        if(!h && !w && !x) return 0;
        y = 1, steps = 0;
        memset(maze, '.', sizeof(maze));
        memset(visited, -1, sizeof(visited));
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cin >> maze[i][j];
            }
        }
        while(maze[y][x] != '.' && visited[y][x] == -1){
            if(visited[y][x] == -1)
                visited[y][x] = steps;
            //printf("visited[%d][%d] = %d\n", y, x, visited[y][x]);
            if(maze[y][x] == 'N'){
                y -= 1;
            } else if(maze[y][x] == 'S'){
                y += 1;
            } else if(maze[y][x] == 'E'){
                x += 1;
            } else if(maze[y][x] == 'W'){
                x -= 1;
            }
            steps++;

        }
        if(maze[y][x] == '.'){
            printf("%d step(s) to exit\n", steps);
        } else if(visited[y][x] != -1){
            printf("%d step(s) before a loop of %d step(s)\n", visited[y][x], steps - visited[y][x]);
        }
    }
}
