#include <iostream>
#include <queue>
using namespace std;

struct Obj{
    int ances, least; //the index of the least weight
    bool isGood;
};

struct Edge{
    long long int s, e, w;
    bool operator()(const Edge a, const Edge b){
        return a.w > b.w;
    }
};

long long int N, M, weights[20006], minWeight, mWind, s, e, w;
Obj disjoint[20006];
priority_queue <Edge, vector<Edge>, Edge> que;

void sortOut(int i){
    if(disjoint[i].ances == i) return;
    sortOut(disjoint[i].ances);
    disjoint[i].ances = disjoint[disjoint[i].ances].ances;
    disjoint[i].least = disjoint[disjoint[i].ances].least;
    disjoint[i].isGood = disjoint[disjoint[i].ances].isGood;
}

void disMerge(int i, int j){
    sortOut(i);
    sortOut(j);
    disjoint[disjoint[i].ances].ances = disjoint[j].ances; //join i under j
    disjoint[j].least = (weights[disjoint[disjoint[i].ances].least], weights[disjoint[j].least]);
}

int main(){
    cin >> N >> M;
    cin >> weights[1];
    disjoint[1].ances = 1;
    disjoint[1].least = 1;
    disjoint[1].isGood = false;
    minWeight = weights[1];
    mWind = 1;
    for(int i = 2; i <= N; i++){
        disjoint[i].ances = i, disjoint[i].least = i;
        disjoint[i].isGood = false;
        cin >> weights[i];
        if(weights[i] < minWeight){
            minWeight = weights[i];
            mWind = i;
        }
    }
    Edge ed;
    for(int i = 1; i <= N; i++){
        if(i != mWind){
            ed.s = i;
            ed.e = mWind;
            ed.w = weights[i] + minWeight;
            que.push(ed);
        }
    }
    for(int i = 0; i < M; i++){
        cin >> s >> e >> w;
        ed.s = s;
        ed.e = e;
        ed.w = w;
        que.push(ed);
    }
    long long int ans = 0;
    while(!que.empty()){
        Edge ed = que.top();
        que.pop();
        if(disjoint[ed.s].ances == disjoint[ed.e].ances) continue;
        ans += ed.w;
        cout << "Joined " << ed.s << " to " << ed.e << ", ans now " << ans << endl;
        disMerge(ed.s, ed.e);
    }
    printf("%lld\n", ans);
}
