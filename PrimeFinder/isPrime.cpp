#include <iostream>
using namespace std;

bool isPrime(int num){
    if(num % 2 == 0) return false;
    for(int i = 3; i*i < num; i++){
        if(num % i == 0) return false;
    }
    return true;
}



int main(){
    int cases, a;
    char output;
    while(cin >> cases){
        for(int i = 0; i < cases; i++){
            cin >> a;
            output = (isPrime(a)) ? 'Y' : 'N';
            cout << output << endl;
        }
    }

}
