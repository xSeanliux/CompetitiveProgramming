#include <iostream>
#define MOD 998244353
using namespace std;

int N;

int main(){
    cin >> N;
    long long int A[N + 1];
    A[1] = 1;
    long long int currentFact = 1;
    for(int i = 2; i <= N; i++){
        currentFact *= i;
        currentFact %= MOD;
        A[i] = ((A[i-1] * i)%MOD - i + currentFact) % MOD;
    }
    printf("%lld\n", A[N]);
}
