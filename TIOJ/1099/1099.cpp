#include <iostream>
#include <stdio.h>
#include <float.h>
#include <math.h>
using namespace std;

int n, a, b, c, x, y, z;

int main(){
    while(cin >> n >> a >> b >> c >> x >> y >> z){
        if(!n) return 0;
        cout << ((a + b + c) == (x + y + z) ? "Yes" : "No") << endl;
    }
}
