#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

long long int c, N, p, q;



int main(){
    cin >> c;
    for(int ia = 1; ia <= c; ia++){
        cin >> N;
        printf("Case %d: ", ia);
        if(N != 1){
            long long int A = N*(N-1);
            int D = 4;
            if(A % 4 == 0){
                A /= 4;
                D = 1;
            } else if(A % 2 == 0){
                A /= 2;
                D = 2;
            }
            if(D == 1){
                printf("%lld\n", A);
            } else {
                printf("%lld/%d\n", A, D);
            }
        } else {
            printf("0\n");
        }
    }
}
