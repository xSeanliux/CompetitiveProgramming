#include <iostream>
#include <math.h>
using namespace std;

int k, m, l, u;

int main(){
    while(cin >> k >> m){
        l = 0;
        u = m;
        while(k > 1){
            l = ceil((u + l)/2);
            cout << "New lBound " << l << endl;
            k--;
            cout << k << " boxes remaining" << endl;
        }
        printf("(%d + %d)*(%d - %d + 1)/2 = %d\n",u, l, u, l, (u + l)*(u - l + 1)/2);
    }
}
