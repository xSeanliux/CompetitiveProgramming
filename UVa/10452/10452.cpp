#include <iostream>
using namespace std;

char arr[100][100], str[] = {'I', 'E', 'H', 'O', 'V', 'A', '#'};
int H, W, T;

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &H, &W);
        int cI, cJ;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                cin >> arr[i][j];
                if(arr[i][j] == '@'){
                    cI = i;
                    cJ = j;
                }
            }
        }

        for(int i = 0; i < 7; i++){
            if(i) printf(" ");
            if(cI > 0 && arr[cI-1][cJ] == str[i]){
                cI--;
                printf("forth");
            } else if(cJ < W-1 && arr[cI][cJ+1] == str[i]){
                cJ++;
                printf("right");
            } else if(cJ > 0 && arr[cI][cJ-1] == str[i]){
                cJ--;
                printf("left");
            }
        }
        printf("\n");
    }
}
