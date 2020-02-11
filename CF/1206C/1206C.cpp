#include <iostream>
using namespace std;

int N, arr[(int)2e5 + 10];

int main(){
    cin >> N;
    if(!(N % 2)){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 0; i < N; i++){
        if(i % 2){
            arr[i] = 2 * N - i + 1;
            arr[i + N] = 2 * N - i;
        } else {
            arr[i] = i + 1;
            arr[i + N] = i + 2;
        }
    }
    for(int i = 0; i < 2 * N; i++){
        cout << arr[i] << " \n"[i==2*N-1];
    }
}
