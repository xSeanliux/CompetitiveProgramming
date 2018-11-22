#include <iostream>
using namespace std;

int c, a, b;

int main(){
    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> a >> b;
        if(b % a != 0){
            cout << -1 << endl;
        } else {
            cout << a << " " << b << endl;
        }
    }
}
