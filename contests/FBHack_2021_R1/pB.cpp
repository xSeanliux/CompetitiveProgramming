#include <iostream>
#include <string.h>
using namespace std;

inline void solve(int tc){
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    if(A <= (N + M - 2) || B <= (N + M - 2)){
        cout << "Case #" << tc << ": Impossible" << endl;
    } else {
        cout << "Case #" << tc << ": Possible" << endl;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                int k = 1;
                if(i == 0 && j == 0){
                    k = A - N - M + 2;
                } else if(i == 0 && j == M - 1){
                    k = B - N - M + 2;
                }
                cout << k << " \n"[j == M - 1];
            }
        }

    } 
}

int main(){
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        solve(i);
    }
}

