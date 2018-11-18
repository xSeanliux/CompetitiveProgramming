#include <iostream>
using namespace std;

int c, a, b;

int rev(int n){ //
    while(!(n % 10))
        n /= 10;
    int k = 0;
    while(n){
        int r = n % 10;
        n -= r;
        k += r;
        n /= 10;
        k *= 10;
    }
    k /= 10;
    return k;
}

int main(){
    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> a >> b;
        cout << rev( rev(a) + rev(b) ) << endl;
    }
}
