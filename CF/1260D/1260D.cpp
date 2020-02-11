#include <iostream>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 226250, INF = 1e9;

struct Obj{
    int pos, dis, dan; //pos, disarm, danger
    Obj(){}
    Obj(int P, int Di, int Da): pos(P), dis(Di), dan(Da){}
    bool operator<(Obj o) const {
        return pos < o.pos;
    }
    void show(){
        cout << "pos: " << pos << ", dis: " << dis << ", dan: " << dan << endl;
    }
} obs[maxN];

int agis[maxN], m, n, k, t;
/*
m = no. of soldiers
n = len of thing
k = traps
t = time limit
*/

bool can(int minTime){
    //cout << "Running can(" << minTime << ")" << endl;
    int ct = n + 1;
    for(int i = 0; i < k; i++){
        if(obs[i].dan > minTime){
            //cout << "Found a trap with ";
            //obs[i].show();
            int currentEnd = obs[i].dis, ori = obs[i].pos;
            while(i < k && obs[i].pos <= currentEnd){
                //cout << "Crossed: ";
                //obs[i].show();
                if(obs[i].dan > minTime)
                    currentEnd = max(currentEnd, obs[i].dis);
                i++;
            }
            i--;
            //cout << "ori = " << ori << ", end = " << currentEnd << endl;
            ct += 2 * (currentEnd - ori + 1);
            //cout << "Adds " <<2 * (currentEnd - ori + 1) << " to time" << endl;
        }
    }
    //cout << "Total time = " << ct << endl;
    return ct <= t;
}

int main(){
    ericxiao;
    cin >> m >> n >> k >> t;
    for(int i = 1; i <= m; i++) cin >> agis[i];
    agis[0] = INF;
    for(int i = 0; i < k; i++){
        cin >> obs[i].pos >> obs[i].dis >> obs[i].dan;
    }
    sort(agis, agis + m + 1, greater<int>());
    sort(obs, obs + k);

    int l = 0, r = m + 1, mid = (l + r) / 2;
    while(l + 1 < r){
        if(can(agis[mid])){
            l = mid;
        } else {
            r = mid;
        }
        mid = (l + r) / 2;
    }
    cout << l << endl;
}

