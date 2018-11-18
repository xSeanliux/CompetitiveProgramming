#include <iostream>
#include <string.h>
using namespace std;

int MAP[50][50];

int N;
int dir;
int y;
int x = y = 0;

void go(int dir){
    if(dir == 0){
        x -= 1;
    } else if(dir == 1){
        y -= 1;
    } else if(dir == 2){
        x += 1;
    } else {
        y += 1;
    }
}



int main(){
    string ans = "";
    while(cin >> N){
        cout << "N: " << N << endl;
        cin >> dir;
        int round = 1;
        //input the thing
        for(int i = 0 ; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> MAP[i][j];
            }
        }



        x = (N-1)/2;
        y = (N-1)/2;
        int lim = 0;
        int goTimes = 0;
        cout << endl << endl;
        int steps = 1;
        while(ans.length()<N*N){

            for(int i = 0; i < steps; i++){
                cout << MAP[y][x] << " ";
                ans += to_string(MAP[y][x]);
                go(dir);

            }
            dir ++;
            dir %=4;
            if(steps != N){
                for(int i = 0; i < steps; i++){
                        cout << MAP[y][x] << " ";
                    ans += to_string(MAP[y][x]);
                    go(dir);

                }
            }

            dir++;
            dir %=4;
            steps++;



        }


        }
        cout << "ANS" << ans << endl;


    }

