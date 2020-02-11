#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct Obj{
    int cap, time, pri, tr;
    Obj(){}
    Obj(int C, int T, int P): cap(C), time(T), pri(P){}
    bool operator<(Obj o) const {
        return pri > o.pri;
    }
};

const int maxN = 5e5 + 10, INF = 1e10;

vector<Obj> objs;
int q, n, m, c, c0, currentTime, a, b, t, seg[maxN * 4], tag[maxN * 4], inv[maxN];

void pull(int id){
    seg[id] = min(seg[2 * id + 1], seg[2 * id + 2]);
}

void push(int id, int l, int r){
    seg[id] += tag[id];
    if(l + 1 < r){
        tag[2 * id + 1] += tag[id];
        tag[2 * id + 2] += tag[id];
    }
    tag[id] = 0;
}

void build(int id = 0, int l = 0, int r = n + 1){
    tag[id] = 0;
    if(l + 1 == r){
        seg[id] = c + inv[l] - c0;
        return;
    }
    int m = (l + r) / 2;
    build(2 * id + 1, l, m);
    build(2 * id + 2, m, r);
    pull(id);
}


void modify(int id, int ql, int qr, int l, int r, int val){
    push(id, l, r);
    if(ql >= r || qr <= l) return;
    if(ql <= l && r <= qr){
        tag[id] += val;
        push(id, l, r);
        return;
    }
    int m = (l + r) / 2;
    modify(2 * id + 1, ql, qr, l, m, val);
    modify(2 * id + 2, ql, qr, m, r, val);
    pull(id);
}

int query(int id, int ql, int qr, int l, int r){
    push(id, l, r);
    if(ql >= r || qr <= l) return INF;
    if(ql <= l && r <= qr){
        return seg[id];
    }
    int m = (l + r) / 2;
    return min(query(2 * id + 1, ql, qr, l, m), query(2 * id + 2, ql, qr, m, r));
}

vector<int> lis;

signed main(){
    ericxiao;
    cin >> q;
    while(q--){
        cin >> n >> m >> c >> c0;
        currentTime = c0;
        objs.clear();
        objs.resize(n);
        lis.clear();
        for(int i = 0; i < n; i++){
            cin >> t >> a >> b;
            objs[i] = Obj(a, t, b);
            lis.push_back(t);
        }

        objs.push_back(Obj(0, m, 0));
        sort(objs.begin(), objs.end(), [=](const Obj a, const Obj b){
            return a.time < b.time;
        });
        sort(lis.begin(), lis.end());
        int sz = unique(lis.begin(), lis.end()) - lis.begin();
        for(int i = 0; i <= n; i++){
            objs[i].tr = lower_bound(lis.begin(), lis.begin() + sz, objs[i].time) - lis.begin();
            inv[objs[i].tr] = objs[i].time;
            //cout << "INV[" << objs[i].tr << "] = " << inv[objs[i].tr] << endl;
        }
        //cout << "Sz = " << sz << endl;
        build(0, 0, sz + 1);
        priority_queue<Obj> pq;
        int ans = 0, maxadd, qres;
        Obj o;
        bool isGood = true;
        for(int i = 0; i <= n && isGood; i++){ //want to go to objs[i]
            //cout << "Want to go to to next: " << objs[i].time << endl;
            //cout << "Currenttime = " << currentTime << endl;
            while(currentTime < objs[i].time){
                if(pq.empty()){
                    isGood = false;
                    ans = -1;
                    break;
                }
                o = pq.top();
                pq.pop();
                //cout << "Looking at time = " << o.time << ", cap = " << o.cap << ", pri = " << o.pri << endl;
                qres = query(0, o.tr, sz + 1, 0, sz + 1);
                maxadd = min(min(objs[i].time - currentTime, o.cap), qres);
                o.cap -= maxadd;
                currentTime += maxadd;
                ans += maxadd * o.pri;
                modify(0, o.tr, sz + 1, 0, sz + 1, -maxadd);
                if(o.cap > 0 && qres > 0){
                    pq.push(o);
                }
            }
            pq.push(objs[i]);
        }
        cout << ans << endl;
        /*
        1
        7 9 2 1
        4 1 1
        7 1 7
        1 2 4
        7 1 3
        2 2 1
        3 2 2
        1 1 7
        */
        /*
        -1
        */
    }
}
