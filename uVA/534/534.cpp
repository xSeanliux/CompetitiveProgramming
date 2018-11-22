#include <iostream>
#include<queue>
#include <vector>
#include <cmath>
using namespace std;

int N, _x, _y, c;
float k, l;
class Stone{
public:
    int index;
    float minJump;
    friend bool operator < (const Stone& a, const Stone& b){
        return a.minJump > b.minJump;
    }
};



bool visited[205];
float x[205], y[205];

float dist(int a, int b){
    return sqrt(pow(x[a]-x[b],2) + pow(y[a]-y[b],2));
}

priority_queue<Stone> toVisit;

int main(){
    c = 0;
    while(cin >> N){
        if(!N) return 0;
        vector<Stone> stones;
        for(int i = 0 ; i < N; i++){
            Stone s;
            s.index = i;
            /*
            if(!i){
                s.minJump = 0;
            } else {
            }
            */
            s.minJump = 1420; //max is 1414
            visited[i] = false;
            cin >> x[i] >> y[i];
            stones.push_back(s);
        }
        stones[0].minJump = 0;

        toVisit = priority_queue<Stone>();
        toVisit.push(stones[0]);
        int now;
        while(!visited[1]){
            Stone s = toVisit.top();
            now = s.index;
            //cout << "now = " << now << endl;
            toVisit.pop();
            if(visited[now]){
                continue;
            }
            visited[now] = true;
            for(int i = 0 ; i < N; i++){
                if(!visited[i]){ //update route
                    k = max(stones[now].minJump, dist(i, now));
                    l = stones[i].minJump;
                    if(k < l){
                        //cout << "Stone " << i << " has now new val of " << k << endl;
                        stones[i].minJump = k;
                        toVisit.push(stones[i]);
                    }
                }
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++c, stones[1].minJump);
        //cout << stones[1].minJump;
    }
}
