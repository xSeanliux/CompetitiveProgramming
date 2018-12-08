#include <iostream>
using namespace std;

long long int arr[30][30], a, b, c;

int main(){
    for(int i = 1; i <= 25; i++){
        arr[2][i] = i;
    }
    for(int i = 3; i <= 25; i++){
        for(int j = 1; j <= 25; j++){
            arr[i][j] = arr[i][j-1] + arr[i-1][j];
        }
    }
    cin >> c;
    for(int i = 0 ; i < c; i++){
        cin >> a >> b;
        cout << arr[a][b] << endl;
    }
}
