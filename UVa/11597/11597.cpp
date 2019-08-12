#include <iostream>
using namespace std;

int C = 0, N;

int main(){
    while(cin >> N){
        if(!N) return;
        printf("Case %d: %d\n", ++C, N/2);
    }
}
