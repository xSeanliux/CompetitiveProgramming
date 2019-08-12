#include <iostream>
using namespace std;

int N;

int main(){
    cin >> N;
    if(N % 2 == 0){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < N; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        cout << (2 * i) % N << " ";
    }
}
