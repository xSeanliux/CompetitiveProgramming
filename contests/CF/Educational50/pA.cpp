#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <math.h>
#include <iomanip>
using namespace std;



int main(){
    unsigned long long int N, K, H;
    scanf("%llu%llu", &N, &K);
    if(!(K % N)){
        printf("%llu\n", K/N);
    } else {
        printf("%llu\n", K/N + 1);
    }
}
