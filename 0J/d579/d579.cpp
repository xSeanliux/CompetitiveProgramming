#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double n;
    double ans;
    while(cin >> n){
        cout << abs((int)(n*100000)) << endl;
        ans = abs((int)(n*100000));
        cout << "|" << n << "|=" << ans/10000 << endl;
    }


}
