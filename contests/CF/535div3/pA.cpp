#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

int N, T, a, b, c, d;
int main(){
    cin >> N;
    while(N--){
        cin >> a >> b >> c >> d;
        if(b == c){
            if(a == d){
                cout << a << " " << c << endl;
            } else {
                cout << a << " " << d << endl;
            }

        } else {
            cout << b << " " << c << endl;
        }
    }
}
