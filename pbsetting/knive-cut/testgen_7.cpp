#include <iostream>
using namespace std;

int main(){
    cout << "500 20" << endl;
    for(int i = 0; i < 500; i++){
        cout << 1000000000;
        cout << " \n"[i == 499];
    }
}