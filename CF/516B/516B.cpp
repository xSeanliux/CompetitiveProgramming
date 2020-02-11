#include <iostream>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2020, INF = 7122;

int N, M, dirs[4][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1},
};
char mp[maxN][maxN];
bool visited[maxN][maxN];
queue<pii> que;

//dir: 0123: ULDR

inline bool isValid(int y, int x, int dir){
    if(mp[y][x] != '.') return false;
    if(y && x && y <= N && x <= M){
        return mp[y + dirs[dir][0]][x + dirs[dir][1]] == '.';
    }
    return false;
}

inline int getDir(int y, int x){
    if(mp[y][x] != '.' || y < 1 || x < 1 || y > N || x > M) return -1;
    int r = -1;
    for(int i = 0; i < 4; i++){
        if(isValid(y, x, i) && r == -1){
            r = i;
        } else if(isValid(y, x, i) && r != -1) return -1;
    }
    return r;
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> mp[i][j];
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            int d = getDir(i, j);
            if(d != -1 && !visited[i][j]){
                que.push({i, j});
                visited[i][j] = true;
                visited[i + dirs[d][0]][j + dirs[d][1]] = true;
            }
        }
    }
    pii tp;
    while(que.size()){
        tp = que.front();
        que.pop();
        if(mp[tp.F][tp.S] != '.') continue;
        int d = getDir(tp.F, tp.S);
        if(d == 0){
            mp[tp.F][tp.S] = 'v';
            mp[tp.F - 1][tp.S] = '^';
        } else if(d == 1){
            mp[tp.F][tp.S] = '>';
            mp[tp.F][tp.S - 1] = '<';
        } else if(d == 2){
            mp[tp.F][tp.S] = '^';
            mp[tp.F + 1][tp.S] = 'v';
        } else if(d == 3){
            mp[tp.F][tp.S] = '<';
            mp[tp.F][tp.S + 1] = '>';
        }
        visited[tp.F + dirs[d][0]][tp.S + dirs[d][1]] = true;
        for(int i = tp.F - 2; i <= tp.F + 2; i++){
            for(int j = tp.S - 2; j <= tp.S + 2; j++){
                if(!visited[i][j] && getDir(i, j) != -1){
                    que.push({i, j});
                    //cout << "Pushing " << i << ", " << j << endl;
                    visited[i][j] = true;
                }
            }
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(mp[i][j] == '.'){
                cout << "Not unique" << endl;
                return 0;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << mp[i][j];
        }
        cout << endl;
    }
}
