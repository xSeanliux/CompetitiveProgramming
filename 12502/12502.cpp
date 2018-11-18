#include <iostream>
using namespace std;

int T, x, y, z;

int main(){
    cin >> T;
    while(T--){
        cin >> x >> y >> z;
        cout << z * (3*x - x - y) / (x + y) << endl;
    }
}
