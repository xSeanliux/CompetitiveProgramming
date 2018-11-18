#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int N, c;

int main(){
    while(cin >> N){
        if(!N) return 0;
        int a =  floor(log2(N));
        printf("%d\n", a);
    }
}
