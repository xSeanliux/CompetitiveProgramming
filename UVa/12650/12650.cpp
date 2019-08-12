#include <iostream>
using namespace std;

int N, K, t;

int main(){
    while(cin >> N >> K){
        bool hasReturned[N + 1];
        for(int i = 1; i <= N; i++) hasReturned[i] = false;
        if(N == K) cout << "*";
        for(int i = 0; i < K; i++){
            cin >> t;
            hasReturned[t] = true;
        }
        for(int i = 1; i <= N; i++){
            if(!hasReturned[i]){
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
