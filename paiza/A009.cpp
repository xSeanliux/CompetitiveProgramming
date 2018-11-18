#include <iostream>
using namespace std;
int height;
int width;





int main(){
    while(cin >> height >> width){
        char MAP[height][width];
        for(int i = 0; i < height; i++){
            for(int j = 0;  j < width; j++){
                MAP[i][j] = cin.get();
                while(MAP[i][j] == '\n'){
                    MAP[i][j] = cin.get();
                }
            }
        }

        int x = 0;
        int y = 0;
        int vx = 1;
        int vy = 0;
        int steps = 0;
        while(x >= 0 && y >= 0 && x < width && y < height){
            if(MAP[y][x] == '_'){

            } else if(MAP[y][x] == '/'){
                if(vx == 0){
                    if(vy == 1){
                        vx = -1;
                        vy = 0;
                    } else if(vy == -1){
                        vx = 1;
                        vy = 0;
                    }
                } else { //vy = 0
                    if(vx == 1){
                        vy = -1;
                        vx = 0;
                    } else if(vx == -1){
                        vy = 1;
                        vx = 0;
                    }

                }

            } else if(MAP[y][x] == '\\'){
                if(vx == 0){
                    if(vy == 1){
                        vx = 1;
                        vy = 0;
                    } else if(vy == -1){
                        vx = -1;
                        vy = 0;
                    }
                } else { //vy = 0
                    if(vx == 1){
                        vy = 1;
                        vx = 0;
                    } else if(vx == -1){
                        vy = -1;
                        vx = 0;
                    }

                }
            }
            //cout <<  x << ", " << y << endl;
            x += vx;
            y += vy;
            steps++;
        }
        cout << steps << endl;
    }
}
