#include <iostream>
#include <queue>
using namespace std;

int N, K, v, team[(int)2e5 + 10];
priority_queue<pair<int, int> > pq;

struct Node{
    int val;
    Node *l, *r;
    Node(){}
    Node(int val): val(val), l(NULL), r(NULL){}
} *nodes[(int)2e5 + 10];


void toggleTeam(int &t){
    if(t == 1) t = 2;
    else t = 1;
}

int main(){
    cin >> N >> K;
    nodes[0] = new Node(-1); //start
    for(int i = 1; i <= N; i++){
        cin >> v;
        pq.push({v, i});
        nodes[i] = new Node(i);
        team[i] = 0;
    }
    nodes[N + 1] = new Node(-1);
    nodes[0]->r = nodes[1];
    nodes[N + 1]->l = nodes[N];
    for(int i = 1; i <= N; i++){
        nodes[i]->r = nodes[i+1];
        nodes[i]->l = nodes[i-1];
    }
    int currentTeam = 1;

    while(!pq.empty()){
        auto p = pq.top();
        while(pq.size() && team[p.second] != 0){
            pq.pop();
            p = pq.top();
        }
        if(team[p.second] != 0) break;
        //cout << "Choosing val = " << p.first << " at " << p.second << endl;
        team[p.second] = currentTeam;
        Node *goR = nodes[p.second]->r, *goL = nodes[p.second]->l;
        for(int i = 0; goR->val != -1 && i < K; i++, goR = goR->r){
            team[goR->val] = currentTeam;
            //printf("team[%d] = %d\n", goR->val, currentTeam);
        }
        for(int i = 0; goL->val != -1 && i < K; i++, goL = goL->l){
            team[goL->val] = currentTeam;
            //printf("team[%d] = %d\n", goL->val, currentTeam);
        }
        goL->r = goR;
        goR->l = goL;
        toggleTeam(currentTeam);
        //cout << "NExT" << endl;
    }
    for(int i = 1; i <= N; i++) cout << team[i];
}
