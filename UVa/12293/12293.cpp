#include <iostream>
using namespace std;

int N;

int main(){
    while(cin >> N){
        if(!N) return 0;
        if(!(N % 2)) cout << "Alice" << endl;
        else {
            /*
            Odd -> Even(Small), Odd(Large) -> Even
            */
        }
    }
}
