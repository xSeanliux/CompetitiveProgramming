#include <iostream>
#include <vector>
#include <queue>
#define INF 214748364
using namespace std;

int N, Q, a, b, c, C = 0;

struct Path{
    int des, wei;
};

vector<Path> con[100 + 5];
int label[100 + 5][2]; //0 for smallest, 1 for second smallest
queue<int> que;
bool isInQueue[100 + 5];

int main(){
    while(cin >> N >> Q){
        printf("Set #%d\n", ++C);
        for(int i = 0 ; i < N; i++){
            con[i].clear();
        }
        for(int i = 0 ; i < Q; i++){
            cin >> a >> b >> c;
            Path p;
            p.des = a;
            p.wei = c;
            con[b].push_back(p);
            p.des = b;
            con[a].push_back(p);
        }

        cin >> Q;
        for(int i = 0 ; i < Q; i++){
            cin >> a >> b;
            que = queue<int>();
            for(int i = 0 ; i < N; i++)
                for(int j = 0 ; j < 2; j++)
                    label[i][j] = INF;
            label[a][0] = 0;
            label[a][1] = INF;
            que.push(a);
            while(!que.empty()){
                int Z = que.front();
                //cout << endl << "Checking node " << Z << endl;
                Path p;
                for(int i = 0 ; i < con[Z].size(); i++){
                    p = con[Z][i];
                    //cout << "road to " << p.des << ", weight " << p.wei << endl;
                    if(label[Z][0] != INF && label[Z][0] + p.wei < label[p.des][1]){
                        if(label[Z][0] + p.wei < label[p.des][0]){
                            label[p.des][1] = label[p.des][0];
                            label[p.des][0] = label[Z][0] + p.wei;
                            //cout << "shortest route to " << p.des << " now " << label[p.des][0] << endl;
                            //cout << "2nd shortest route to " << p.des << " now " << label[p.des][1] << endl;
                            if(!isInQueue[p.des]){
                                que.push(p.des);
                                isInQueue[p.des] = true;
                            }
                        } else if(label[Z][0] + p.wei > label[p.des][0]){
                            label[p.des][1] = label[Z][0] + p.wei;
                            //cout << "2nd shortest route to " << p.des << " now " << label[p.des][1] << endl;
                            if(!isInQueue[p.des]){
                                que.push(p.des);
                                isInQueue[p.des] = true;
                            }
                        }
                        if(label[Z][1] != INF && label[Z][1] + p.wei > label[p.des][0] && label[Z][1] + p.wei < label[p.des][1]){
                            label[p.des][1] = label[Z][1] + p.wei;
                            //cout << "2nd shortest route to " << p.des << " now " << label[p.des][1] << endl;
                            if(!isInQueue[p.des]){
                                que.push(p.des);
                                isInQueue[p.des] = true;
                            }
                        }
                    }
                }
                isInQueue[Z] = false;
                que.pop();
            }
            if(label[b][1] == INF){
                cout << "?" << endl;
            } else {
                cout << label[b][1] << endl;
            }
        }
    }
}


