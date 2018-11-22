#include <iostream>
using namespace std;
int main(){

    int m, n;
    while(cin >> m >> n){
        int arr[m][n], transposed[n][m];
        for(int i = 0; i < m; i++){
            for(int j = 0 ; j < n; j++){
                cin >> arr[i][j];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0 ; j < n; j++){

                transposed[j][i] = arr[i][j];
            }
        }

        cout << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m; j++){
                cout << transposed[i][j] << " ";
            }
            cout << endl;
        }


    }
}
