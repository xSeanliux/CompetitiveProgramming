#include <iostream>
using namespace std;

int n, m, k;

int main(){
    cin >> n >> m >> k;
    cout << (m - 1) + (n - 1) + (n * m) - 1 << endl;
    for(int i = 0; i < m - 1; i++) cout << 'L';
    for(int i = 0; i < n - 1; i++) cout << 'U';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 1; j++){
            cout << (i & 1 ? 'L' : 'R');
        }
        if(i < n - 1) cout << 'D';
    }
}
