#include <iostream>
using namespace std;

int a, b, c;

int main(){
    while(cin >> a >> b >> c){
        if(a + b > c){
            cout << "Hunters win!" << endl;
        } else {
            cout << "Props win!" << endl;
        }
    }
}
