#include <iostream>
#include <vector>
#include <queue>
#define int long long int
#define pii pair<int,int>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


const int seaDist = 1e7, INF = 1e18;
bool visited[2003][2019];
int N, M, si, sj, ei, ej, minDist[2003][2019];
char mp[2003][2019];


int getDist(int i, int j){
    return mp[i][j] == '#' ? 1 : seaDist;
}

signed main(){
    ericxiao;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> mp[i][j];
            minDist[i][j] = INF;
        }
    }
    cin >> si >> sj >> ei >> ej;
    si--, sj--, ei--, ej--;

    minDist[si][sj] = 0;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>  > pq;
    pq.push({0, {si, sj}});
    pair<int, pii> p;
    pii pos;
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        pos = p.second;
        if(pos.first < 0 || pos.second < 0 || pos.first >= N || pos.second >= M || visited[pos.first][pos.second]) continue;
        if(pos.first > 0 && !visited[pos.first - 1][pos.second] && minDist[pos.first - 1][pos.second] > minDist[pos.first][pos.second] + getDist(pos.first - 1, pos.second)){
            minDist[pos.first - 1][pos.second] = minDist[pos.first][pos.second] + getDist(pos.first - 1, pos.second);
            pq.push({minDist[pos.first - 1][pos.second], {pos.first - 1, pos.second}});
        }
        if(pos.first < N - 1 && !visited[pos.first + 1][pos.second] && minDist[pos.first + 1][pos.second] > minDist[pos.first][pos.second] + getDist(pos.first + 1, pos.second)){
            minDist[pos.first + 1][pos.second] = minDist[pos.first][pos.second] + getDist(pos.first + 1, pos.second);
            pq.push({minDist[pos.first + 1][pos.second], {pos.first + 1, pos.second}});
        }
        if(pos.second > 0 && !visited[pos.first][pos.second - 1] && minDist[pos.first][pos.second - 1] > minDist[pos.first][pos.second] + getDist(pos.first, pos.second - 1)){
            minDist[pos.first][pos.second - 1] = minDist[pos.first][pos.second] + getDist(pos.first, pos.second - 1);
            pq.push({minDist[pos.first][pos.second - 1], {pos.first, pos.second - 1}});
        }
        if(pos.second < M - 1 && !visited[pos.first][pos.second + 1] && minDist[pos.first][pos.second + 1] > minDist[pos.first][pos.second] + getDist(pos.first, pos.second + 1)){
            minDist[pos.first][pos.second + 1] = minDist[pos.first][pos.second] + getDist(pos.first, pos.second + 1);
            pq.push({minDist[pos.first][pos.second + 1], {pos.first, pos.second + 1}});
        }
    }
    cout << minDist[ei][ej] / seaDist << endl;
}
