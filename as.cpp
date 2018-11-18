#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

long long int N, K;

int main(){
    cin >> N >> K;
    if(K > 2*N -1){
        cout << 0 << endl;
    } else {
        if(K % 2){
            long long int U = (K-1)/2 + 1;
            long long int L = (K-1)/2;
            cout << min(L, N - U + 1) << endl;
        } else {
            long long int U = K/2 + 1;
            long long int L = K/2 - 1;
            cout << min(L, N - U + 1) << endl;
        }
    }
}
