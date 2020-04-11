#include <iostream>
using namespace std;

int q, a, b;

int main(){
    cin >> q;
    while(q--){
        cin >> a >> b;
        cout << (b - a % b) % b << endl;
    }
}
