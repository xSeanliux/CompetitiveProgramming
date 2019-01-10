#include <iostream>
using namespace std;

int N, c;

int main(){
    cin >> c;
    for(int i = 1; i <= c; i++){
        cin >> N;
        printf("Case #%d: %d\n", i, 2*N - 1);
    }
}


