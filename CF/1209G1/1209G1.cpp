#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxC = 2e5 + 10;
bool has[maxC];
int N, q, numcnt = 0, frq[maxC], res;
vector<int> vec;
vector<pii> times;
map<int, pii> pos;

inline int getmode(int l, int r){
    vector<int> toundo = vector<int>();
    res = 0;
    for(int i = l; i <= r; i++){
        frq[vec[i]]++;
        res = max(res, frq[vec[i]]);
        toundo.push_back(vec[i]);
    }
    for(int i : toundo) frq[i]--;
    return res;
}


int main(){
    ericxiao;
    fill(frq, frq + maxC, 0);
    cin >> N >> q; //q = 0
    vec.resize(N);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
        if(!pos.count(vec[i])) pos[vec[i]] = {i, i};
        else pos[vec[i]].S = i;
    }
    for(auto p : pos){
        times.push_back({p.S.F, p.F});
        times.push_back({p.S.S, p.F});
        //cout << p.F << " START: " << p.S.F << ", END: " << p.S.S << endl;
    }
    sort(times.begin(), times.end());
    fill(has, has + maxC, false);
    int ans = 0;
    int cl = 0, cr;
    for(pii p : times){
        //cout << "time = " << p.F << ", num = " << p.S << endl;
        if(!has[p.S]){
            has[p.S] = true;
            numcnt++;
        } else {
            has[p.S] = false;
            numcnt--;
        }
        if(!numcnt){
            //cout << "HEY" << endl;
            cr = p.F;
            ans += (cr - cl + 1) - getmode(cl, cr);
            cl = cr + 1;
        }
    }
    cout << ans << endl;
}
