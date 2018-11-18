#include <iostream>
using namespace std;

long long int cc, a, lim, len;


int main(){
    cc = 1;
    while(cin >> a >> lim){
        long long int ori = a;
        if(a <= 0 && lim <= 0) return 0;
        len = 0;
        while(a != 1 && a <= lim){
            if(a % 2 == 0){
                a /= 2;
            } else {
                a = 3*a + 1;
            }
            len++;
        }
        if(a == 1 ) len++;
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n", cc, ori, lim, len);
        cc++;
    }
}
