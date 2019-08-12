#include <iostream>
#include <math.h>
using namespace std;

unsigned long long int N, M, K, L, ans;
// N types, have K
// M friends, at least L
// each friend give x.
// x * M <= N -> x <= N/M
// x * M >= L + K -> (N - L) / M >= x
// x = M/min(L, K)

int main(){
    scanf("%llu%llu%llu%llu", &N, &M, &K, &L);
    if(!((L + K) % M)) ans = (L + K) / M;
    else ans = (L + K)/M + 1;
    if(ans <= N/M) printf("%llu\n", ans);
    else cout << -1 << endl;
}
