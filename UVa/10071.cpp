#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
double n;
long long int


int main(){
    while(cin >> n){
        double Z = 0;
        for(int i = 1; i <= n; i++){
            Z += pow(i,3);
        }
        double N = pow(n*(n+1),2)/4;
        printf("%.100g\n",N);
        printf("%.100g\n",Z);
    }

}
