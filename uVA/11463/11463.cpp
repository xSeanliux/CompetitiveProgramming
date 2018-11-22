#include <iostream>
using namespace std;

int c, N, R, S, E;
int shortest[100][100];
bool isConnected[100][100];


int main(){
    cin >> c;
    for(int ri = 1; ri <= c; ri++){
        cin >> N >> R;
        for(int i = 0 ; i < N; i++){

            for(int j = 0; j < N; j++){
                shortest[i][j] = 10000;
                isConnected[i][j] = false;
            }
        shortest[i][i] = 0;
        }
        int a, b;
        for(int k = 0; k < R; k++){
            cin >> a >> b;
            isConnected[a][b] = true;
            isConnected[b][a] = true;
            shortest[a][b] = 1;
            shortest[b][a] = 1;
        }
        cin >> S >> E;
        for(int i = 0 ; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0 ; k < N; k++){
                    if(shortest[j][i] + shortest[i][k] < shortest[j][k]){
                        //cout << "shortest[" << j << "][" << k << "] = " << shortest[k][j] << endl;
                        shortest[j][k] = shortest[j][i] + shortest[i][k];
                        //cout << "UPDATED TO" << shortest[k][j] << endl;

                    }
                }
            }
        }
        int maxLen = 0;
        for(int i = 0 ; i < N; i++){
            if(shortest[S][i] + shortest[i][E] > maxLen){
                maxLen = shortest[S][i] + shortest[i][E];
            }
        }
        printf("Case %d: %d\n", ri, maxLen);
    }

}
