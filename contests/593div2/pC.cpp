#include <iostream>
#include <vector>
using namespace std;

int n;

int main(){
    cin >> n;
    int ans[n][n], cnt = 0;
    for(int i = 0; i < n; i++){
        if(i % 2){
            for(int j = n - 1; j >= 0; j--){
                ans[j][i] = ++cnt;
            }
        } else {
            for(int j = 0; j < n; j++){
                ans[j][i] = ++cnt;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
