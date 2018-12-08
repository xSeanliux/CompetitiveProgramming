#include <iostream>
#include <queue>
#include <vector>
#define INF 2147483647
using namespace std;

int W, H, t;

int maze[1000][1000], minDist[1000][1000];
bool visited[1000][1000];

class Obj{
public:
    int y;
    int x;
    int currentDist;
    bool operator()(const Obj a, const Obj b){
        return a.currentDist > b.currentDist;
    }
};

int main(){
    cin >> t;
    while(t--){
        cin >> H >> W;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                cin >> maze[i][j];
                visited[i][j] = 0;
                minDist[i][j] = INF;
            }
        }
        minDist[0][0] = maze[0][0];
        Obj o;
        o.y = o.x = 0;
        o.currentDist = maze[0][0];
        priority_queue <Obj, vector<Obj>, Obj> que;
        que.push(o);
        while(!que.empty() && !visited[H-1][W-1]){
            Obj o = que.top();
            while(visited[o.y][o.x]){
                que.pop();
                o = que.top();
            }
            /*
            printf("The current coords: (%d, %d)\n\n", o.x, o.y);
            for(int i = 0; i < H; i++){
                for(int j = 0; j < W; j++){
                    cout << minDist[i][j] << " ";
                }
                cout << endl;
            }
            */
            if(o.y > 0 && !visited[o.y-1][o.x]){
                minDist[o.y-1][o.x] = min(minDist[o.y-1][o.x], minDist[o.y][o.x] + maze[o.y-1][o.x]);
                Obj _o;
                _o.y = o.y-1;
                _o.x = o.x;
                _o.currentDist = minDist[o.y-1][o.x];
                que.push(_o);
            }
            if(o.x > 0 && !visited[o.y][o.x-1]){
                minDist[o.y][o.x-1] = min(minDist[o.y][o.x-1], minDist[o.y][o.x] + maze[o.y][o.x-1]);
                Obj _o;
                _o.y = o.y;
                _o.x = o.x-1;
                _o.currentDist = minDist[o.y][o.x-1];
                que.push(_o);
            }
            if(o.x < W-1 && !visited[o.y][o.x+1]){
                minDist[o.y][o.x+1] = min(minDist[o.y][o.x+1], minDist[o.y][o.x] + maze[o.y][o.x+1]);
                Obj _o;
                _o.y = o.y;
                _o.x = o.x+1;
                _o.currentDist = minDist[o.y][o.x+1];
                que.push(_o);
            }
            if(o.y < H-1 && !visited[o.y+1][o.x]){
                minDist[o.y+1][o.x] = min(minDist[o.y+1][o.x], minDist[o.y][o.x] + maze[o.y+1][o.x]);
                Obj _o;
                _o.y = o.y+1;
                _o.x = o.x;
                _o.currentDist = minDist[o.y+1][o.x];
                que.push(_o);
            }
            visited[o.y][o.x] = true;
        }
        cout << minDist[H-1][W-1] << endl;
    }

}
