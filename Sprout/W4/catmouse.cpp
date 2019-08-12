#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct Obj{
    int x, y, dist;
    Obj(int y, int x, int dist): x(x), y(y), dist(dist){}
    Obj(){}
};

int H, W, catY, catX, ans;
char mp[100][100];
string s;
queue<Obj> que;

int main(){
    while(cin >> H){
        W = 0;
        if(!H) return 0;
        for(int i = 0; i < H; i++){
            cin >> s;
            if(!W) W = s.length();
            for(int j = 0; j < W; j++){
                mp[i][j] = s[j];
                if(s[j] == 'K'){
                    catY = i;
                    catX = j;
                }
            }
        }
        que = queue<Obj>();
        que.push(Obj(catY, catX, 0));
        Obj tp;
        bool canDo = false;
        while(!que.empty()){
            tp = que.front();
            que.pop();
            //cout << "(" << tp.y << ", " << tp.x << "): " << tp.dist << endl;
            if(tp.y < 0 || tp.x < 0 || tp.y >= H || tp.x >= W || mp[tp.y][tp.x] == '#') {
                //cout << "NOPE" << endl;
                continue;
            } else {
                if(mp[tp.y][tp.x] == '@'){
                    canDo = true;
                    ans = tp.dist;
                    break;
                }
                //cout << "PUSHING" << endl;
                mp[tp.y][tp.x] = '#';
                que.push(Obj(tp.y, tp.x + 1, tp.dist + 1));
                que.push(Obj(tp.y, tp.x - 1, tp.dist + 1));
                que.push(Obj(tp.y + 1, tp.x, tp.dist + 1));
                que.push(Obj(tp.y - 1, tp.x, tp.dist + 1));
            }
        }
        if(!canDo){
            cout << "= =\"" << endl;
        } else {
            cout << ans << endl;
        }
    }
}
