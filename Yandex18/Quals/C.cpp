#include <iostream>
#include <math.h>

using namespace std;

long long int N;

int main(){
    cin >> N;
    int k = N;

    long long int exp = (N-1) * (N-1);
    for(int i = 0 ; i < exp - 1; i++){
        N *= k;
        N %= 1000000007;
    }
    printf("%lld\n", N);
}
