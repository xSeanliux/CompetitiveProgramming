#include <iostream>
using namespace std;

long long int C, a, b, k;

int main(){
    cin >> C;
    while(C--){
        cin >> a >> b >> k;
        if(k % 2){
            printf("%lld\n", a + (k-1)/2 * (a-b));
        } else {
            printf("%lld\n", (k)/2 * (a-b));
        }
    }
}
