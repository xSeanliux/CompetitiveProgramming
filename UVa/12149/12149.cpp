#include <iostream>
using namespace std;
double c, N;

int main(){
    while(cin >> N){
        if(!N) return 0;
        c = N*(N+1)*(2*N+1)/6;
        printf("%.0f\n",c);
    }
}
