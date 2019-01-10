#include <iostream>
#include <string.h>
using namespace std;

int c, N, H; //N symbols, H ones
char s[20];
bool hasPrinted = false;

void dfs(int ite, int currentOnes){
    if(ite >= N){
        if(currentOnes == H){
            for(int i = 0; i < N; i++){
                printf("%c", s[i]);
            }
            printf("\n");
        }
        return;
    }
    s[ite] = '0';
    dfs(ite + 1, currentOnes);
    if(currentOnes < H){
        s[ite] = '1';
        dfs(ite + 1, currentOnes + 1);
    }

}



int main(){
    scanf("%d", &c);
    for(int i = 0 ; i < c; i++){
        scanf("%d %d", &N, &H);
        if(hasPrinted)
            printf("\n");
        else
            hasPrinted = true;
        dfs(0, 0);

    }
}
