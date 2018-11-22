#include <iostream>
#include <math.h>
using namespace std;

int a, b;

int main(){
    while(cin >> a >> b){
        if(a == -1 && b == -1) return 0;
        if(a < b) swap(a, b); //a is always larger
        printf("%d\n", min(b + 100 - a, a - b));
    }
}
