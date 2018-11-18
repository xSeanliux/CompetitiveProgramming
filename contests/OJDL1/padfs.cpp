#include <iostream>
using namespace std;

int n, m, k, x, y, ans = 0;

bool arr[20040][20030];

void dfs(int x, int y){
    //cout << "Running dfs(" << y << ", " << x << ")" << endl;
    if(x < 0 || x > 2 * n || y < 0 || y > 2 * m || !arr[y][x]){
        return;
    } else {
        arr[y][x] = 0;
        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
    }
}


int main(){
    cin >> n >> m >> k;
    for(int i = 0 ; i <= 2 * m; i++){
        for(int j = 0; j <= 2 * n; j++){
            arr[i][j] = 0;
        }
    }
    for(int i = 0 ; i < k; i++){
        cin >> x >> y;
        arr[y + m][x + n] = 1;
    }
    /*
    for(int i = 0 ; i <= 2 * m; i++){
        for(int j = 0; j <= 2 * n; j++){
            cout << arr[i][j] << " ";
        }
        cout<< endl;
    }
    */

    for(int i = 0 ; i <= 2*m; i++){
        for(int j = 0; j <= 2*n; j++){
            if(arr[i][j]) {
                    ans++;
                    //cout << "Found: " << i <<", " << j << endl;
                    dfs(j, i);
                    /*
                    for(int i = 0 ; i <= 2 * m; i++){
                        for(int j = 0; j <= 2 * n; j++){
                            cout << arr[i][j] << " ";
                        }
                        cout<< endl;
                    }
                    */
            }


            //cout << endl;
        }
    }
    cout << ans << endl;

}
