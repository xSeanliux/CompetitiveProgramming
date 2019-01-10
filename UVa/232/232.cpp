#include <iostream>
using namespace std;

int H, W, pznum = 0;
bool hasEnter = false;

int main(){
    while(cin >> H){
        if(!H) return 0;
        cin >> W;
        char across[H][W], down[H][W];
        int ind[H][W];
        for(int i = 0 ; i < H; i++){
            for(int j = 0; j < W; j++){
                cin >> across[i][j];
                ind[i][j] = 0;
                down[i][j] = across[i][j];
            }
        }
        int _ind = 0;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(across[i][j] == '*') continue;
                if(!(i*j)){
                    ind[i][j] = ++_ind;
                } else if(across[i-1][j] == '*'){
                    ind[i][j] = ++_ind;
                } else if(across[i][j-1] == '*'){
                    ind[i][j] = ++_ind;
                }
                //cout << "A: " << ind[i][j] << " ";
            }
            //cout << endl;
        }
        //begin output
        if(hasEnter) cout << endl;
        else hasEnter = true;
        printf("puzzle #%d:\nAcross\n", ++pznum);
        for(int i = 0 ; i < H; i++){
            for(int j = 0; j < W; j++){
                if(across[i][j] != '*'){
                    printf("%3d.", ind[i][j]);
                    while(across[i][j] != '*' && j < W){
                        printf("%c", across[i][j]);
                        across[i][j] = '*';
                        j++;
                    }
                    printf("\n");
                    j--;
                }
            }
        }
        printf("Down\n");
        for(int i = 0 ; i < H; i++){
            for(int j = 0; j < W; j++){
                int currentI = i;
                if(down[i][j] != '*'){
                    printf("%3d.", ind[i][j]);
                    while(down[currentI][j] != '*' && currentI < H){
                        printf("%c", down[currentI][j]);
                        down[currentI][j] = '*';
                        currentI++;
                    }
                    printf("\n");
                    j--;
                }
            }
        }
    }
}
