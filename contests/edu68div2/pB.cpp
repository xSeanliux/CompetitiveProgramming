#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int T, N, M;
string s;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        char mp[N][M];
        vector<int> h, v;
        h.resize(N);
        v.resize(M);
        fill(h.begin(), h.end(), 0);
        fill(v.begin(), v.end(), 0);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> mp[i][j];
                if(mp[i][j] == '*'){
                    h[i]++;
                    v[j]++;
                }
            }
        }
        int maxAns = -1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                maxAns = max(maxAns, h[i] + v[j] - (mp[i][j] == '*'));
            }
        }
        cout << (N + M - 1) - maxAns << endl;
    }
}
