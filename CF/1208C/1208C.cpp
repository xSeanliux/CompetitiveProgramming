#include <iostream>
using namespace std;

int N, ans[1000][1000], arr[4][4] = { {0, 4, 1, 5}, {8, 12, 9, 13}, {10, 14, 11, 15}, {2, 6, 3, 7} };

int main(){
    cin >> N;
    int cnt = 0;
    for(int i = 0; i < N; i += 4){
        for(int j = 0; j < N; j += 4){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 4; l++){
                    ans[i + k][j + l] = arr[k][l] + cnt;
                }
            }
            cnt += 16;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
