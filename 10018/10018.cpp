#include <iostream>
using namespace std;
long long int N, c;

long long int rev(long long int N){
    long long int res = 0;
    while(N > 0){
        res *= 10;
        res += N % 10;
        N -= (N % 10);
        N /= 10;
    }
    return res;
}

int main(){
    cin >> c;
    for(int i = 1; i <= c; i++){
        cin >> N;
        long long int r = rev(N);
        int n = 0;
        if(N == r){
            N += r;
            r = rev(N);
            n++;
        }
        while(r != N){
            N += r;
            r = rev(N);
            n++;

        }
        printf("%lld %lld\n", n, N);
    }
}
