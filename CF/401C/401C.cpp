#include <iostream>
#include <string.h>
using namespace std;

int N, M;

string ans = "";

int abs(int x){
    return (x > 0) ? x : -x;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    if(N < M - 1 || N > 2 * (M + 1)){
        cout << "-1" << endl;
        return 0;
    }
    if(N == M - 1){
        cout << "0";
        for(int i = 0; i  < N; i++){
            cout << "10";
        }
        cout << endl;
        return 0;
    }
    while(M){
        if(N > M){
            cout << "1";
            N--;
        }
        cout << "10";
        N--, M--;
    }
    while(N > 0){
        cout << "1";
        N--;
    }
    cout << endl;
}
