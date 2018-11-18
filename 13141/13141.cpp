#include <iostream>
using namespace std;
int N;
long long int fib[90];

void getfib(){
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 1;
    for(int i = 3; i <= 85; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int main(){
    getfib();
    while(cin >> N){
        if(!N) return 0;
        else
            printf("%lld\n", fib[N]);
    }
}

