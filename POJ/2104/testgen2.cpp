#include <iostream>
using namespace std;

int a = 5000, b = 5000;

int main(){
    cout << a << " " << b << endl;
    for(int i = 1; i <= a; i++) cout << i << " ";
    cout << endl;
    for(int i = 1; i <= b; i++){
        cout << "1 " << a << " " << i << endl;
    }
}

