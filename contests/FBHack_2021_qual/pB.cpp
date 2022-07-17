#include <iostream>
using namespace std;

const int maxN = 52, INF = 1e9;
int tc, hor[maxN], vert[maxN];
char mp[maxN][maxN];
string s;

inline void solve(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) hor[i] = vert[i] = N;
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < N; j++){
            mp[i][j] = s[j];
            if(s[j] == 'X'){
                hor[i]--;
                vert[j]--;
            } else if(s[j] == 'O'){
                hor[i] = INF;
                vert[j] = INF;
            }
        }
    }
    int minV = INF, minC = 0;
    for(int i = 0; i < N; i++){
        if(hor[i] < minV){
            minV = hor[i];
            minC = 1;
        } else if(hor[i] == minV) minC++;
        if(vert[i] < minV){
            minV = vert[i];
            minC = 1;
        } else if(vert[i] == minV) minC++;
    }
    if(minV == 1){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
               if(mp[i][j] == '.' &&  hor[i] == 1 && vert[j] == 1) minC--;
            }
        }
    }
    cout << "Case #" << ++tc << ": ";
    if(minV > N) cout << "Impossible";
    else cout << minV << " " << minC;
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
