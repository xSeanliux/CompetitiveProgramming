#include <iostream>
#include <vector>
using namespace std;


int P, Y;
bool isPrime(int x){
    for(int i = 2; i*i <= x; i++) if(!(x % i)) return false;
    return true;
}

int minFactor(int x){
    for(int i = 2; i*i <= x; i++) if(!(x % i)) return i;
    return x;
}

int main(){
    cin >> P >> Y;
    int mP = P;
    for(int i = Y; i >= 0; i--){
        if(minFactor(i) > P){
            cout << i << endl;
            return 0;
        } else if(isPrime(i)){
            cout << -1 << endl;
            return 0;
        }
    }
}
