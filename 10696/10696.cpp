#include <iostream>
using namespace std;


int f91(int N){
    if( N <= 100 ){
        return f91(f91(N + 11));
    } else {
        return N - 10;
    }
}

int main(){
    int N;
    while(cin >> N){
        if(!N) return 0;
        else cout << "f91(" << N << ") = " << f91(N) << endl;
    }
}
