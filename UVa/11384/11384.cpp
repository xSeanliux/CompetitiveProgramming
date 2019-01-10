#include <iostream>
#include <math.h>
using namespace std;

int N;

int main(){
    while(cin >> N){
        if(N == 1) cout << 1 << endl;
        else
            printf("%.0f\n", ceil(log2(N + 1)));
    }
}
