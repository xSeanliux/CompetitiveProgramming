#include <iostream>
#include <math.h>
using namespace std;

int r1, r2, r3;

int main(){
    printf("200000 200000\n");
    for(int i = 1; i <= 200000; i++) printf(" %d", i);
    printf("\n");
    for(int i = 1; i <= 200000; i++){
        r1 = rand() % 200000 + 1;
        r2 = rand() % 200000 + 1;
        r3 = rand() % 200000 + 1;
        printf("2 %d %d\n", min(r1, r2), max(r1, r2));
    }
}
    /*
    for(int i = 1; i <= 200000; i++){
        r1 = rand() % 200000 + 1;
        r2 = rand() % 200000 + 1;
        r3 = rand() % 200000 + 1;
        if(rand() % 2){
            printf("1 %d %d %d\n", min(r1, r2), max(r1, r2), r3);
        } else {
            printf("2 %d %d\n", min(r1, r2), max(r1, r2));
        }
    }
}
    */
