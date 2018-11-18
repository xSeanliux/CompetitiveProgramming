#include <iostream>
#include <math.h>
using namespace std;

int N, A;
double r;

int main(){
    while(cin >> N >> A){
        r = 0;
        for(int i = 1; i<= N; i++){
            r += i * pow(A, i);
        }
        printf("%.0f\n",r);
    }
}
