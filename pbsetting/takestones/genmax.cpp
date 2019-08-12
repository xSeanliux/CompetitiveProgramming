#include <iostream>
using namespace std;

int main(){
    cout << 5000 << " "<< 2500 << endl;
    for(int i = 1; i <= 5000; i++){
        cout << i << " \n"[i == 5000];
    }
}
