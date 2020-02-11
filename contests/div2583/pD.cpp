#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int n, m;

inline bool hasbit(int i, int j){
    return (i & (1LL << j)) > 0;
}

int main(){
    cin >> n >> m;
    char mp[n][m];
    int isreachable[n][m][2];
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            mp[i][j] = s[j];
        }
    }
    if(n == 1 || m == 1){
        for(int i = 0; i <n ; i++){
            for(int j = 0; j < m; j++){
                if(mp[i][j] == '#'){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
        cout << 1 << endl;
        return 0;
    }
    isreachable[0][1][0] = (mp[0][1] == '.');
    isreachable[0][1][1] = false;
    isreachable[1][0][0] = false;
    isreachable[1][0][1] = (mp[1][0] == '.');
    for(int i = 2; i < m; i++){
        if(mp[0][i] == '#'){
            isreachable[0][i][0] = false;
        } else {
            isreachable[0][i][0] = isreachable[0][i - 1][0];
        }

        isreachable[0][i][1] = false;
    }
    for(int i = 2; i < n; i++){
        if(mp[i][0] == '#'){
            isreachable[i][0][1] = false;
        } else {
            isreachable[i][0][1] = isreachable[i - 1][0][1];
        }

        isreachable[i][0][0] = false;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(mp[i][j] == '#'){
                isreachable[i][j][0] = isreachable[i][j][1] = false;
            } else {
                isreachable[i][j][0] = (isreachable[i][j - 1][0] || isreachable[i - 1][j][0]);
                isreachable[i][j][1] = (isreachable[i][j - 1][1] || isreachable[i - 1][j][1]);
            }
        }
    }




    int ans = 10000;
    //check if ans = 0
    if(!(isreachable[n - 1][m - 2][0] | isreachable[n - 1][m - 2][1] | isreachable[n - 2][m - 1][0] | isreachable[n - 2][m - 1][1])){
        cout << 0 << endl;
        return 0;
    }
    //check if ans = 1
    int ans = N + M;
    for(int i = 1; i < M; i++){
        int t = 0;
        for(int k = 0; k < N; k++){
            if(i - k < 0 || i - k >= M) continue;
            if(isreachable[k][i - k][0] || isreachable[k][i - k][1]) t++;
        }
        ans = min(t, ans);
    }
    for(int i = 1; i < N - 1; i++){
        int t = 0;
        for(int k = 0; k < M; k++){
            if(M - 1 + i - k < 0 || M - 1 + i - l >= N) continue;
            if(isreachble[M - 1 + i - k][k][0] || isreachable[M - 1 + i - k][1]) t++;
        }
        ans = min(t, ans);
    }
    cout << 2 << endl;

}
