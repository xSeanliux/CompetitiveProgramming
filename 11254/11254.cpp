#include <iostream>
#include <math.h>
using namespace std;

int N;

bool isPow2(int n){
    while(!(n % 2)){
        n /= 2;
    }
    return (n == 1);
}

int maxPow2(int n){
    int res = 1;
    while(!(n % 2)){
        n /= 2;
        res *= 2;
    }
    return res;
}

int main(){
    while(cin >> N){
        if(N == -1)
            return 0;
        if(isPow2(N))
            printf("%d = %d + ... + %d\n", N, N, N);
        else{
            N *= 2;
            int q = maxPow2(N);
            int p = N/maxPow2(N);
            cout << "q = " << q << ", p = " << p << endl;
            int k = max(q, p) - 1;
            int a =  ( abs(q - p) + 1 ) / 2;
            printf("%d = %d + ... + %d\n", N/2, a, a + k);
        }
    }

}
