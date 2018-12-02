#include <iostream>
#include <math.h>
#define FACTOR sin(0.6*acos(-1))/sin(acos(-1)*0.35)
using namespace std;

int main(){
    double len;
    while(cin >> len){
        printf("%.10f\n", len*FACTOR);
    }
}
