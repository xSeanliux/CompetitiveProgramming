#include <iostream>
using namespace std;

long long int C, N, X, K;

int main(){
    cin >> C;
    for(int i = 1; i <= C; i++){
        cin >> N >> K >> X;
        printf("Case %d: %lld\n", i, (N*(N+1) - (2*X + K - 1)*K)/2);
    }
}
