#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char M[31][31][31];
bool visited[31][31][31];
int minDist[31][31][31];
int L, W, C, x, y, z, targx, targy, targz, minAns;
const int INF = 2147483647;

struct Point{
    int x, y, z;
};

bool isVisited(Point p){
    return visited[p.z][p.y][p.x];
}

bool setVisited(Point p, bool b){
    visited[p.z][p.y][p.x] = b;
}

int getDist(Point p){
    return minDist[p.z][p.y][p.x];
}

void setDist(Point p, int val){
    minDist[p.z][p.y][p.x] = val;
}

struct Obj{
    int dist;
    Point p;
};

class myc{
public:
    bool operator()(const Obj a, const Obj b){
        return a.dist < b.dist;
    }
};


int main(){
    while(cin >> L >> W >> C){
        if(!L && !W && !C) return 0;
        for(int i = 0; i < L; i++){
            for(int j = 0; j < W; j++){
                for(int k = 0; k < C; k++){
                    cin >> M[i][j][k];
                    visited[i][j][k] = false;
                    minDist[i][j][k] = INF;
                    if(M[i][j][k] == 'S'){
                        x = k;
                        y = j;
                        z = i;
                        minDist[i][j][k] = 0;
                    } else if(M[i][j][k] == '#'){
                        visited[i][j][k] = true;
                    } else if(M[i][j][k] == 'E'){
                        targx = k;
                        targy = j;
                        targz = i;
                    }
                }
            }
        }
        priority_queue<Obj, vector<Obj>, myc> que;
        Obj o, q;
        o.dist = 0;
        o.p.x = x;
        o.p.y = y;
        o.p.z = z;
        que.push(o);
        while(!visited[targz][targy][targx] && !que.empty()){
            while(!que.empty() && isVisited(que.top().p)){
                que.pop();
            }
            o = que.top();
            setVisited(o.p, true);
            printf("Next: %d, %d, %d\n", o.p.z, o.p.y, o.p.x);
            q = o;
            q.dist++;
            q.p.x = o.p.x + 1;
            if(getDist(q.p) > q.dist){
                printf("Pushing: %d, %d, %d\n", q.p.z, q.p.y, q.p.x);
                que.push(q);
            }
            q = o;
            q.p.x = o.p.x - 1;
            if(getDist(q.p) > q.dist){
                printf("Pushing: %d, %d, %d\n", q.p.z, q.p.y, q.p.x);
                que.push(q);
            }
            q = o;
            q.p.x = o.p.x + 1;
            if(getDist(q.p) > q.dist){
                printf("Pushing: %d, %d, %d\n", q.p.z, q.p.y, q.p.x);
                que.push(q);
            }
            q = o;
            q.p.y = o.p.y + 1;
            if(getDist(q.p) > q.dist){
                printf("Pushing: %d, %d, %d\n", q.p.z, q.p.y, q.p.x);
                que.push(q);
            }
            q = o;
            q.p.y = o.p.y - 1;
            if(getDist(q.p) > q.dist){
                printf("Pushing: %d, %d, %d\n", q.p.z, q.p.y, q.p.x);
                que.push(q);
            }
            q = o;
            q.p.z = o.p.z + 1;
            if(getDist(q.p) > q.dist){
                printf("Pushing: %d, %d, %d\n", q.p.z, q.p.y, q.p.x);

                que.push(q);
            }
            q = o;
            q.p.z = o.p.z - 1;
            if(getDist(q.p) > q.dist){
                que.push(q);
            }
        }
        if(minDist[targz][targy][targx] == INF){
            cout << "Trapped!" << endl;
        } else {
            cout << minDist[targz][targy][targx] << endl;
        }

    }
}
