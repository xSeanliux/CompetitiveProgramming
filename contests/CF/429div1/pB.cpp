#include <iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int arr[N][M], lu[N][M], ld[N][M], ru[N][M], rd[N][M];
    for(int i = 0 ; i < N; i++)
        for(int j = 0 ; j < M; j++)
            cin >> arr[i][j];
    lu[0][0] = arr[0][0];
    ld[0][N-1] = arr[0][N-1];
    for(int i = 0 ; i < N; i++){

    }
}
