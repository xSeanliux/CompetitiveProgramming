#include <iostream>
#include <math.h>
using namespace std;

long long int n;

int main(){
    while(scanf("%d", &n) != EOF){
        if((long long int)ceil((n+0.0)/9) % 2 == 0){
            printf("Ollie wins.\n");
        } else {
            printf("Stan wins.\n");
        }
    }
}
