#include <iostream>
#include <math.h>
using namespace std;

long long int K;

int main(){
    while(scanf("%d", &K)){
        long long int n = floor( (1 + sqrt(8*K - 7))/2.0 );
        long long int oriN = n;
        n = n*(n-1)/2 + 1;
        printf("%lld/%lld\n", oriN - (K - n + 1) + 1, (K - n + 1));
    }
}
