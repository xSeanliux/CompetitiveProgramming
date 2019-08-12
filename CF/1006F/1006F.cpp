#include <iostream>
#include <utility>
#include <map>
#define int long long int

#define pii pair<int,int>
using namespace std;

const int maxN = 20;

int N, M, k, vals[maxN + 1][maxN + 2], dp[maxN + 1][maxN + 2];
map<int, int> mp[maxN + 1][maxN + 2];

signed main(){
    cin >> N >> M >> k;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> vals[i][j];
        }
    }
    if(N == 1 && M == 1){
        cout << (vals[0][0] == k) << endl;
        return 0;
    }
    mp[0][0].insert({vals[0][0], 1});
    mp[N - 1][M - 1].insert({vals[N - 1][M - 1], 1});
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if((i + j) >= (N + M) / 2){
                continue;
            }
            if(i){
                for(auto p : mp[i - 1][j]){
                    mp[i][j][p.first ^ vals[i][j]] += p.second;
                }
            }
            if(j){
                for(auto p : mp[i][j - 1]){
                    mp[i][j][p.first ^ vals[i][j]] += p.second;
                }
            }
        }
    }
    for(int i = N - 1; i >= 0; i--){
        for(int j = M - 1; j >= 0; j--){
            if((i + j) < (N + M) / 2){
                continue;
            }
            if(i < N - 1){
                for(auto p : mp[i + 1][j]){
                    mp[i][j][p.first ^ vals[i][j]] += p.second;
                }
            }
            if(j < M - 1){
                for(auto p : mp[i][j + 1]){
                    mp[i][j][p.first ^ vals[i][j]] += p.second;
                }
            }
        }
        //cout << endl;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            //cout << "for (" << i << ", " << j << ")" << endl;
            //for(auto p : mp[i][j]){
            //    cout << p.first << ", " << p.second << endl;
            //}
        }
    }
    int ans = 0;

    for(int i = 0; i < max(N, M); i++){
        int j = (N + M) / 2 - i - 1;
        //cout << "i = " << i << ", j = " << j << endl;
        if(j < M && j >= 0){
            if(i < N - 1){
                for(auto p : mp[i][j]){
                    ans += mp[i + 1][j][p.first ^ k] * p.second;
                }
            }
            if(j < M - 1){
                for(auto p : mp[i][j]){
                    ans += mp[i][j + 1][p.first ^ k] * p.second;
                }
            }
        }
    }



    cout << ans << endl;

}

