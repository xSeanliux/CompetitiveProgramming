#include <iostream>
using namespace std;

double fact(int x){
    if(x == 1 | x == 0){
        return 1;
    } else {
        return x * fact(x-1);
    }
}


int main(){
    int n;
    for(int n = 0; n < 200; n++)
        cout << n << "! = " << fact(n) << endl;



}
