#include <iostream>
#include <math.h>
using namespace std;

long long int A, c;

long long int arm(int n){
    int res = 0, Z = A, rem;
    while(Z > 0){
        rem = Z % 10;
        res += pow(rem, n);
        //cout << "res += " << rem << "^" << n << endl;
        Z -= rem;
        Z /= 10;
    }
    return res;
}


int main(){
    cin >> c;
    for(int j = 0 ; j < c; j++){
        //cout << "j = " << j << endl;
        cin >> A;
        int K = floor(log10(A)) + 1;
        if(arm(K) != A){
            cout << "Not Armstrong" << endl;
        } else if(arm(K) == A){
            cout << "Armstrong" << endl;
        }

    }
}
