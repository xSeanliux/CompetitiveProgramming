#include <iostream>
using namespace std;

int T, N, K;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        for(int i = 0 ; i < N; i++){
            printf("%c", (i % K) + 'a');
        }
        printf("\n");
    }
}
