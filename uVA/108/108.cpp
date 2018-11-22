#include <iostream>
using namespace std;

int N;

int main(){
    cin >> N;
    int arr[N][N], sum[N][N], ans = -200;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            ans = max(ans, arr[i][j]);
        }
    }
    sum[0][0] = arr[0][0];
    for(int i = 1; i < N; i ++){
        sum[i][0] = arr[i][0] + sum[i-1][0];
        sum[0][i] = arr[0][i] + sum[0][i-1];
    }
    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + arr[i][j];
        }
    }
    /*
    cout << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    */
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k <= i; k++){
                for(int l = 0; l <= j; l++){
                    int S = sum[i][j];
                    if(k > 0)
                        S -= sum[k-1][j];
                    if(l > 0)
                        S -= sum[i][l-1];
                    if(k > 0 && l > 0)
                        S += sum[k-1][l-1];
                    ans = max(ans, S);
                }
            }
        }
    }
    cout << ans << endl;
}
