#include <iostream>
using namespace std;

const int maxN = 1 << 10, INF = 1e8;
int arr[maxN][maxN], dir[maxN][maxN][4];

void solve() {
    int N, M;
    cin >> N >> M;
    string s;
    for(int i = 1; i <= N; i++) {
        cin >> s;
        for(int j = 1; j <= M; j++) arr[i][j] = (s[j - 1] == 'B');
    }
    for(int i = 0; i <= max(N, M); i++) {
        for(int k = 0; k < 4; k++) {
            dir[i][M + 1][k] = dir[i][0][k] = dir[0][i][k] = dir[N + 1][i][k] = -INF;
        }
    }
    for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) {
        if(arr[i][j]) {
            dir[i][j][0] = i + j;
            dir[i][j][1] = i - j;
            dir[i][j][2] = - i + j;
            dir[i][j][3] = - i - j;
        } else {
            dir[i][j][0] = dir[i][j][1] = dir[i][j][2] = dir[i][j][3] = -INF;
        }
    }
    for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) {
        dir[N - i + 1][M - j + 1][0] = max(dir[N - i + 1][M - j + 1][0], dir[N - i + 2][M - j + 1][0]);
        dir[N - i + 1][M - j + 1][0] = max(dir[N - i + 1][M - j + 1][0], dir[N - i + 1][M - j + 2][0]);
        dir[N - i + 1][M - j + 1][0] = max(dir[N - i + 1][M - j + 1][0], dir[N - i + 2][M - j + 2][0]);

        dir[N - i + 1][j][1] = max(dir[N - i + 1][j][1], dir[N - i + 2][j][1]);
        dir[N - i + 1][j][1] = max(dir[N - i + 1][j][1], dir[N - i + 1][j - 1][1]);
        dir[N - i + 1][j][1] = max(dir[N - i + 1][j][1], dir[N - i + 2][j - 1][1]);

        dir[i][M - j + 1][2] = max(dir[i][M - j + 1][2], dir[i - 1][M - j + 1][2]);
        dir[i][M - j + 1][2] = max(dir[i][M - j + 1][2], dir[i][M - j + 2][2]);
        dir[i][M - j + 1][2] = max(dir[i][M - j + 1][2], dir[i - 1][M - j + 2][2]);

        dir[i][j][3] = max(dir[i][j][3], dir[i - 1][j][3]);
        dir[i][j][3] = max(dir[i][j][3], dir[i][j - 1][3]);
        dir[i][j][3] = max(dir[i][j][3], dir[i - 1][j - 1][3]);
    }
    int best = INF, bestI = -1, bestJ = -1;
    for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) {
        int w = i + j + dir[i][j][3];
        w = max(w, i - j + dir[i][j][2]);
        w = max(w, - i + j + dir[i][j][1]);
        w = max(w, - i - j + dir[i][j][0]);
        if(best > w) {
            best = w;
            bestI = i, bestJ = j;
        }
    }
    //cout << "best = " << best << endl;
    cout << bestI << " " << bestJ << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) solve();
}
