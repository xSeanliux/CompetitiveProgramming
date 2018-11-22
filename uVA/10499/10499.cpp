#include <iostream>
using namespace std;

double N;

int main(){
    while(cin >> N){
        if(N < 0) return 0;
        if(N == 1) printf("0%%\n");
        else printf("%.0f%%\n", 25*N);
    }
}
