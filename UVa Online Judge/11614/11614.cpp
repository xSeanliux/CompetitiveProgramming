#include <iostream>
#include <math.h>
using namespace std;

long long int c, n;

int main(){
    cin >> c;
    while(c--){
        cin >> n;
        //cout << sqrt(8*n + 1)/2 << endl;
        long long int ans = floor((sqrt(8*n + 1) - 1)/2);
        printf("%lld\n", ans);
    }
}
