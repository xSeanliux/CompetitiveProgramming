#include <iostream>
#include <math.h>
using namespace std;
int N, c;

long long int H(int n){
    cout << "Running H(" << n << ") = " << endl;
    cout << "n * log(" << n << ") = " << n*log(n) << endl;
    long long res = n;
    cout << n;
    for(long long int i = 2; i <= n; i=i+1){
        res = (res + n/i);
        cout << " + " << n/i;
    }
    cout << endl << "= " << res << endl;
    return res;
}

int main(){
    cin >> c;
    for(int i = 1; i <= c; i++){
        H(i);
    }
}
