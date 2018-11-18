#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int c, m, n, days;

char grid[100 + 4][100 + 69];
string cS;

bool isWin(char a, char b){
    if((a == 'R' && b == 'P') || (a == 'P' && b == 'S') || (a == 'S' && b == 'R')) return false;
    return true;
}

char updateGrid(int y, int x){
    bool hasChanged = false;
    if(y != 0){
        if(!hasChanged){
            hasChanged = !(isWin(grid[y][x], grid[y-1][x]));
        }
    }
    if(y != m-1){
        if(!hasChanged){
            hasChanged = !(isWin(grid[y][x], grid[y+1][x]));
        }
    }
    if(x != 0){
        if(!hasChanged){
            hasChanged = !(isWin(grid[y][x], grid[y][x-1]));
        }
    }
    if(x != n-1){
        if(!hasChanged){
            hasChanged = !(isWin(grid[y][x], grid[y][x+1]));
        }
    }
    if(hasChanged){
        if(grid[y][x] == 'R'){
           return 'P';
        } else if(grid[y][x] == 'S'){
            return  'R';
        } else{
            return  'S';
        }
    }
    return grid[y][x];
}

void updateMap(){
    char nGrid[m+5][n+5];
    for(int i = 0 ; i < m; i++){
        for(int j = 0; j < n; j++){
            nGrid[i][j] = updateGrid(i, j);
        }
    }
    for(int i = 0 ; i < m; i++){
        for(int j = 0; j < n; j++){
            grid[i][j] = nGrid[i][j];
        }
    }
}


int main(){
    cin >> c;
    for(int k = 0; k < c; k++){
        cin >> m >> n >> days;
        if(k > 0) cout << endl;
        int lim = m*n;
        int counter = 0;
        while(counter < lim){
            cin >> cS;
            int l = cS.length();
            for(int i = 0; i < l; i++){
                grid[(int)(floor(counter/n))][counter%n] = cS[i];
                counter++;
            }
        }

        //cout << "b" << lim << endl;

        for(int i = 0; i < days; i++){
            updateMap();
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << grid[i][j];
            }

            cout << endl;
        }


    }
}
