#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int fib[100000];

long long int n, b, c;

int main(){
    c = 0;
    int a = 1; b = 1;

    while(cin >> n >> b){
        if(n == 0 && b == 0) return 0;
        fib[0] = 1%b;
        fib[1] = 1%b;
        for(int i = 2; i <= n; i++){
            fib[i] = (fib[i-1] + fib[i-2] + 1) % b;
            if(i == 100000 - 1){
                int a = fib[i-1];
                int b = fib[i-2];
                wmemset(fib, 0, sizeof(fib));
                fib[0] = b;
                fib[1] = a;
                n -= 100000;
                i = 2;
            }
        }

    }
    printf("Case %d: %d %d %d\n", ++c, n, b, fib[n]);

}
