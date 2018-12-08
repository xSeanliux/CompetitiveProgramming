#include <iostream>
#include <math.h>
using namespace std;

int c;
double n;
int main(){
    c = 1;
    while(cin >> n){
        if(n < 0) return 0;
        int result = ceil(log2(n));
        printf("Case %d: %d\n", c, result);
        c++;
    }

}
