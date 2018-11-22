#include <iostream>
#include <math.h>
using namespace std;

long int s, n, a, b;


int main(){
    cin >> s;
    for(int k = 0 ; k < s; k++){
        cin >> n;
        n;
        a = pow(2, n-1);
        if(n < 5) printf("%d\n", a);
        else {
            a = n*(n-1)/2;
            b = n*(n-1)*(n-2)*(n-3)/24;
            printf("%lld\n", a + b + 1);
        }
    }
}
