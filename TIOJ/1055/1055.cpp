#include <iostream>
using namespace std;

int a, b;

int main(){
    cin >> a >> b;
    if(a > b)
        for(int i = a; i >= b; i--){
            for(int j = 0; j <= i; j++) cout << "*\n"[j == i];
        }
    else
        for(int i = a; i <= b; i++){
            for(int j = 0; j <= i; j++) cout << "*\n"[j == i];
        }
}
