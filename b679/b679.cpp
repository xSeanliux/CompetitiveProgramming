#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double N;
    long long int H;
    while(cin >> N){
        //cout << N << endl

        H = (-1+sqrt(1+8*N))/2;
        cout << H << endl;
    }
}
