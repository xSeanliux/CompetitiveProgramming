#include <iostream>
#define int long long int
using namespace std;

int N, M, values[11][100010], where[11][100010];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> values[i][j];
            where[i][values[i][j]] = j;
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j + i < N; j++){
            bool isGood = true, isEnd = false;
            for(int k = 0; k < M; k++){
                //cout << "j = " << j << endl;
                //cout << "Checking vals[" << 0 << "] " << i + j << " with vals[" << k << "][" << where[k][ values[0][i] ] + j << "]" << endl;
                if(where[k][ values[0][i] ] + j >= N){
                    isEnd = true;
                    //cout << "is end" << endl;
                    break;
                }
                if(values[k][ where[k][ values[0][i] ] + j ] != values[0][i + j]){
                    isGood = false;
                    break;
                }
            }
            if(!isGood){
                ans += (j + 1) * j / 2;
                i += j - 1;
                //cout << "ans += " << (j + 1) * j / 2 << endl;
                break;
            } else if(isEnd) {
                i += j - 1;
                ans += (j + 1) * (j + 0) / 2;
                //cout << "ans += " << (j + 1) * (j + 0) / 2 << endl;
                break;
            } else if(j + i == N - 1){
                i += j;
                ans += (j + 1) * (j + 2) / 2;
                //cout << "ans += " << (j + 1) * (j + 2) / 2 << endl;
            }
        }
    }
    cout << ans << endl;
}
