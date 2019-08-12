#include <iostream>
using namespace std;

long long int currentRand = 101, tests = 500;

long long int Rand(){
    return currentRand = (currentRand * currentRand + 1) % 0xdefaced;
}

int main(){
    for(int i = 0; i < tests; i++){
        long long int n = Rand() % 50 + 1;
        cout << n << endl;
        for(int j = 0; j < n; j++){
            cout << Rand() << " ";
        }
        cout << endl;
    }

}
