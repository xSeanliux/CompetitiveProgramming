#include <iostream>
using namespace std;
char map[101][101];
int max_x, max_y, dimension;
int startx, starty;

void run(int y, int x){
    if(y >= max_y | x >= max_x | y < 0 | x < 0) return;
    if(map[y][x] == '+') return;
    map[y][x] = '+';
    run(y-1, x);
    run(y+1, x);
    run(y, x-1);
    run(y, x+1);
}



int main(){
    while(cin >> dimension){
            max_x = dimension;
            max_y = dimension;
            for(int i = 0; i < max_y; i++){
                for(int j = 0; j < max_x; j++){
                    cin >> map[i][j];
                }
            }
            cin >> starty >> startx;
            run(starty, startx);

            for(int i = 0; i < max_y; i++){
                for(int j = 0; j < max_x; j++){
                    cout << map[i][j];
                }
                cout << endl;
            }


    }


}
