#include <iostream>
using namespace std;
int main(){

    int m, n;

    while(cin >> m >> n){
        char Map[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> Map[i][j];
            }
        }
        cout << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << Map[i][j];
            }
            cout << endl;
        }
    }

}
