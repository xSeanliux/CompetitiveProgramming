#include <iostream>
using namespace std;


char maze[100 + 50][100 + 50];
int m, n;

int main(){
    int field = 0;
    while(cin >> m >> n){
        if(m == 0 && n == 0){
            return 0;
        } else {

            field++;
            if(field > 1) cout << endl;
            for(int i = 0; i <= m+1; i++){
                for(int j = 0; j <= n+1; j++){
                    maze[i][j] = '0';
                }
            }
            for(int i = 1; i <= m; i++){
                for(int j = 1; j <= n; j++){
                    cin >> maze[i][j];
                }
            }
            for(int i = 1; i <= m; i++){
                for(int j = 1; j <= n; j++){
                    if(maze[i][j] != '*'){
                        int mines = 0;
                        for(int k = i-1; k <= i+1; k++){
                             for(int l = j - 1; l <= j+1; l++){
                                 if(l == j && k == i) continue;
                                 if(maze[k][l] == '*') mines++;
                             }
                        }
                        maze[i][j] = to_string(mines)[0];
                    }
                }
            }
            printf("Field #%d:\n", field);
            for(int i = 1; i <= m; i++){
                for(int j = 1; j <= n; j++){
                    cout << maze[i][j];
                }
                cout << endl;

            }



        }
    }
}


