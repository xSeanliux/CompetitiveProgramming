#include <iostream>
#include <math.h>
using namespace std;

int coeffs[10], first;

int main(){
    while(cin >> coeffs[0]){

        if(!coeffs[0])
            first = -1;
        else
            first = 0;
        for(int i = 1; i < 9; i++){
            cin >> coeffs[i];
            if(first < 0 && coeffs[i] != 0){
                first = i;
            }
        }
        if(first == -1 || first == 8){
            printf("%d\n", coeffs[8]);
            continue;
        }

        if(coeffs[first] == -1){
            printf("-");
        } else if(coeffs[first] != 1) {
            printf("%d", coeffs[first]);
        }
        printf("x");
        if(first < 7){
            printf("^%d", 8 - first);
        }
        //printf("x^%d", 8 - first);

        for(int i = first + 1 ; i < 9; i++){
            if(coeffs[i] != 0){
                printf(" %c ", (coeffs[i] > 0 ? '+' : '-'));
                if(abs(coeffs[i]) != 1 || i == 8){
                    printf("%d", abs(coeffs[i]));
                }
                if(i < 8){
                    printf("x");
                }
                if(i < 7){
                    printf("^%d", 8 - i);
                }

            }



        }
        printf("\n");
    }
}
