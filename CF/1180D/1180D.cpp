#include <iostream>
using namespace std;

int N, M;

int main(){
    cin >> M >> N;
    for(int i = 1; i <= N/2; i++){
        for(int j = 1; j <= M; j++){
            cout << j << " " << i << '\n';
            cout << M + 1 - j << " " << N + 1 - i << '\n';
        }
    }
    if(N % 2){
        for(int i = 1; i <= M/2; i++){
            cout << i << " " << (N + 1)/2 << '\n';
            cout << M + 1 - i << " " << (N + 1)/2 << '\n';
        }
        if(M % 2){
            cout << (M + 1)/2 << " " << (N + 1)/2 << '\n';
        }
    }
}

