#include <iostream>
#include <queue>
#include <math.h>
#define INF 2147483647
using namespace std;

int N, currentEnergy, sR, eR, fl;

struct Room{
     int e, nCon, rs[105];
} rooms[105];

int labels[105]; //label: max amount of energy when you get there
bool isInQue[105];
queue <int> que;

int main(){
    while(cin >> N){
        que = queue<int>();
        if(N == -1) return 0;
        fl = 0;
        currentEnergy = 100;
        for(int i = 1 ; i <= N; i++){
            cin >> rooms[i].e >> rooms[i].nCon;
            isInQue[i] = false;
            if(rooms[i].e == 0){
                if(fl == 0){
                    sR = i;
                    fl++;
                } else {
                    eR = i;
                }
            }
            labels[i] = -INF;
            for(int j = 0; j < rooms[i].nCon; j++){
                cin >> rooms[i].rs[j];
            }
        }
        labels[sR] = 100;
        que.push(sR);
        while(!que.empty()){
            int ind = que.front();
            //cout << "Checking room " << ind << endl;
            for(int i = 0 ; i < rooms[ind].nCon; i++){
                if(labels[ind] + rooms[rooms[ind].rs[i]].e > max(labels[rooms[ind].rs[i]], 0) && labels[rooms[ind].rs[i]] < 10000){
                    //cout << "Max energy to room " << rooms[ind].rs[i] << " is now " << labels[ind] + rooms[rooms[ind].rs[i]].e << endl;
                    labels[rooms[ind].rs[i]] = labels[ind] + rooms[rooms[ind].rs[i]].e;
                    if(!isInQue[rooms[ind].rs[i]]){
                        que.push(rooms[ind].rs[i]);
                    }
                }
            }
            que.pop();
        }
        if(labels[eR] == -INF){
            cout << "hopeless" << endl;
        } else {
            cout << "winnable" << endl;
        }
    }



}
