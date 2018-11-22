#include <iostream>
#include <math.h>
using namespace std;

int mat[100][100];

int cX, cY, n, sC, sR, c = 0;
bool isCorrupt;
int main(){
    while(cin >> n){
        if(!n) return 0;
        cX = -1, cY = -1;
        isCorrupt = false;
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n; j++){
                cin >> mat[i][j];
            }
        }
        //check for corrupt columns and rows at the same time
        for(int i = 0 ; i < n; i++){
            sC = 0, sR = 0;
            for(int j = 0 ; j < n; j++){
                sR += mat[i][j];
                sC += mat[j][i];
                if(j == n-1){
                    if(sR % 2 != 0){
                        if(cY == -1){
                            cY = i;
                        } else {
                            isCorrupt = true;
                            break;
                        }
                    }
                    if(sC % 2 != 0){
                        if(cX == -1){
                            cX = i;
                        } else {
                            isCorrupt = true;
                            break;
                        }
                    }
                }
            }
        }
        if(cX * cY < 0){
            isCorrupt = true;
        }
        if(isCorrupt){
            cout << "Corrupt" << endl;
        } else {
            if(cX == -1){
                cout << "OK" << endl;
            } else {
                printf("Change bit (%d,%d)\n", ++cY, ++cX);
            }
        }

    }
}
