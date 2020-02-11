#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
#include <utility>
#include <set>
#include <queue>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int INF = 1e10, LIM = 9e5;
struct Obj{
    int y, x, dp;
    Obj(){}
    Obj(int Y, int X): y(Y), x(X), dp(INF){}
    Obj(int Y, int X, int DP): y(Y), x(X), dp(DP){}
    bool operator<(const Obj &o) const {
        return dp > o.dp;
    }
};

inline int Abs(int a){
    return (a < 0 ? -a : a);
}

inline void getDp(Obj from, Obj &to){
    to.dp = min(to.dp, from.dp + Abs(to.y - from.y) + Abs(to.x - from.x));
}



queue<Obj> que;
int N, M, P, x, minDist[305][305];
bool visited[305][305];
vector<Obj> objs[9000010];
vector<Obj> nv;
inline bool isValid(int y, int x){
    return (x >= 0 && y >= 0 && x < M && y < N && !visited[y][x]);
}

signed main(){
    ericxiao;
    cin >> N >> M >> P;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> x;
            objs[x].push_back(Obj(i, j));
        }
    }
    for(Obj &o : objs[1]){
        o.dp = o.x + o.y;
    }

    int head, newhead;

    for(int i = 2; i <= P; i++){
        if(objs[i].size() * objs[i - 1].size() <= LIM){
            for(Obj &o : objs[i]){
                for(Obj p : objs[i - 1]){
                    getDp(p, o);
                }
            }
        } else {
            sort(objs[i - 1].begin(), objs[i - 1].end(), [=](Obj a, Obj b){
                return a.dp < b.dp;
            });
            que = queue<Obj>();
            head = 0;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    visited[i][j] = false;
                    minDist[i][j] = INF;
                }
            }
            visited[objs[i - 1][0].y][objs[i - 1][0].x] = true;
            que.push(objs[i - 1][0]);
            head = 1;
            Obj o;
            while(que.size()){
                o = que.front();
                que.pop();
                if(head < objs[i - 1].size() && o.dp == objs[i - 1][head].dp){
                    if(isValid(objs[i - 1][head].y, objs[i - 1][head].x)){
                        que.push(objs[i - 1][head]);
                        visited[objs[i - 1][head].y][objs[i - 1][head].x] = true;
                    }
                    head++;
                }
                if(isValid(o.y + 1, o.x)){
                    minDist[o.y + 1][o.x] = o.dp + 1;
                    visited[o.y + 1][o.x] = true;
                    que.push(Obj(o.y + 1, o.x, o.dp + 1));
                }
                if(isValid(o.y - 1, o.x)){
                    minDist[o.y - 1][o.x] = o.dp + 1;
                    visited[o.y - 1][o.x] = true;
                    que.push(Obj(o.y - 1, o.x, o.dp + 1));
                }
                if(isValid(o.y, o.x + 1)){
                    minDist[o.y][o.x + 1] = o.dp + 1;
                    visited[o.y][o.x + 1] = true;
                    que.push(Obj(o.y, o.x + 1, o.dp + 1));
                }
                if(isValid(o.y, o.x - 1)){
                    minDist[o.y][o.x - 1] = o.dp + 1;
                    visited[o.y][o.x - 1] = true;
                    que.push(Obj(o.y, o.x - 1, o.dp + 1));
                }
            }

            for(Obj &o : objs[i]){
                o.dp = minDist[o.y][o.x];
            }
        }

    }
    int ans = INF;
    for(Obj o : objs[P]){
        ans = min(ans, o.dp);
    }
    cout << ans << endl;
}
