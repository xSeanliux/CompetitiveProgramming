#pragma gcc optimize ("O3")
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int T, n, x, belong[(int)1e6 + 10], toDel, c = 0;
bool isinQue[1005];

string s;

struct Obj{
    bool type; //0 for team, 1 for indiv
    int val;
} toDelTeam;



int main(){
    while(cin >> T){
        queue<Obj> teams;
        queue<int> inteam[1005];
        for(int i = 0; i < (int)1e6 + 10; i++) belong[i] = 0;
        for(int i = 1; i <= T; i++){ //ith team
            scanf("%d", &n);
            isinQue[i] = false;
            for(int j = 0; j < n; j++){
                scanf("%d", &x);
                belong[x] = i;
            }
        }
        printf("Line #%d\n", ++c);
        while(cin >> s){
            if(s == "STOP") break;
            if(s == "ENQUEUE"){
                scanf("%d", &x);
                if(!belong[x]){
                    teams.push({0, x});
                    continue;
                }
                inteam[belong[x]].push(x);
                if(!isinQue[belong[x]]){
                    teams.push({1, belong[x]});
                    isinQue[belong[x]] = true;
                }
            } else {
                toDelTeam = teams.front();
                if(!toDelTeam.type){
                    printf("%d\n", toDelTeam.val);
                    teams.pop();
                    continue;
                }
                toDel = inteam[toDelTeam.val].front();
                printf("%d\n", toDel);
                inteam[toDelTeam.val].pop();
                //printf("Team %d has %d members left\n", toDelTeam, inteam[toDelTeam].size());
                if(inteam[toDelTeam.val].empty()){
                    //printf("Popping team %d\n", toDelTeam);
                    teams.pop();
                    isinQue[toDelTeam.val] = false;
                }
            }
        }
    }
}
