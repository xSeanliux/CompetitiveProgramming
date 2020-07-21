#include <iostream>
using namespace std;

int t, n, m, a, b, ans[100][100], sm[100];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m >> a >> b;
        if(n * a != m * b){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int s = 0; s < m; s++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    ans[i][j] = 0;
                    sm[j] = 0;
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < a; j++){
                    ans[i][(j + s * i) % m] = 1;
                    sm[(j + s * i) % m]++;
                }
            }
            bool f = true;
            for(int i = 0; i < m; i++){
                if(sm[i] != b){
                    f = false;
                    break;
                }
            }
            if(f){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        cout << ans[i][j];
                    }
                    cout << endl;
                }
                break;
            }
        }
        
    }
}
