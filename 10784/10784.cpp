#include <iostream>
#include <math.h>
using namespace std;

double k, c;

int main(){
    c = 0;
    while(cin >> k){
        if(!k) return 0;
        printf("Case %.0f: %.0f\n",++c, ceil((3 + sqrt(9 + 8*k))/2));
    }
}
