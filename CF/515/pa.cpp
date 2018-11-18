#include <iostream>
#include <math.h>
using namespace std;

int L, v, l, r, c;

int main(){
    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> L >> v >> l >> r;
        cout << (int)(floor(L/(v + 0.0)) - floor(r/(v + 0.0)) + ceil(l/(v + 0.0)) - 1) << endl;
    }
}
