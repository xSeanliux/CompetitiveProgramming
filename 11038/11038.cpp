#include <iostream>
#include <math.h>
using namespace std;


long long int a, b;

int current(int a, int b){
    a = ceil((a+0.0)/10);
    b = floor((b+0.0)/10);
    return b - a + 1;
}

int main(){
    while(cin >> a >> b){
        int res = 0, r;
        while(a > 0 || b > 0){
            res += current(a, b);
            a = (a - (a % 10))/10;
            b = (b - (b % 10))/10;
            cout << "a, b = " << a <<", " << b << endl;
        }
        cout << res << endl;
    }

}
