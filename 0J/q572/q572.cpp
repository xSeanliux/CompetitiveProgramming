#include <iostream>
using namespace std;

char map[105][105];
int m, n;
void dfs(int y, int x){
    map[y][x] = 'W';
    if(map[y+1][x] == '@'){
        dfs(y+1, x);
    }
    if(map[y+1][x-1] == '@'){
        dfs(y+1, x-1);
    }
    if(map[y+1][x+1] == '@'){
        dfs(y+1, x+1);
    }
    if(map[y][x] == '@'){
        dfs(y, x);
    }
    if(map[y][x-1] == '@'){
        dfs(y, x-1);
    }
    if(map[y][x+1] == '@'){
        dfs(y, x+1);
    }
    if(map[y-1][x] == '@'){
        dfs(y-1, x);
    }
    if(map[y-1][x-1] == '@'){
        dfs(y-1, x-1);
    }
    if(map[y-1][x+1] == '@'){
        dfs(y-1, x+1);
    }

}


bool containsOil(){
    for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(map[i][j] == '@') return true;
        }

    }
    return false;
}

int main()
{

    while(cin >> m >> n){
        if(m*n == 0){
            break;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> map[i][j];
            }
        }
        int deposits = 0;
        while(containsOil()){
            loop:
                for(int i = 0; i < m; i++){
                    for(int j = 0; j < n; j++){
                        if(map[i][j] == '@'){
                            dfs(i, j);
                            deposits++;
                            break;

                        }
                    }
                }
        }
        cout << deposits << endl;

    }
}
