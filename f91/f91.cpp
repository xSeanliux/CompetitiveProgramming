#include <iostream>
using namespace std;

int f91(int N){
    if(N <= 100) return f91( f91(N + 11) );
    else return N - 10;
}

int main(){
    int N;
    while(cin >> N){
        if(N == 0) return 0;
        printf("f91(%d) = %d\n", N, f91(N));
    }
}
