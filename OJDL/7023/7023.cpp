#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 3e5 + 226;

struct Obj{
    int x, y, t, id, type, tag;
    Obj(){}
    Obj(int X, int Y, int T, int TY, int I): x(X), y(Y), t(T), type(TY), id(I), tag(0){}
};

int ans[maxN], N, a, b, c;

vector<Obj> all;
vector<int> lisx, lisy;


/*
for each with type 0, how many with type 1 have x > myx and y > myy and t < myt + x < myx and y < myy and t < my
*/

struct BIT{
    int arr[maxN];
    vector<pii> ops;
    BIT(){
        fill(arr, arr + maxN, 0);
    }
    void modify(int p, int x){
        ops.emplace_back(p, x);
        for(;p <= N; p += (p & -p)) arr[p] += x;
    }
    int query(int p){
        int r = 0;
        for(;p; p -= (p & -p)) r += arr[p];
        return r;
    }
    void undo(){
        for(pii p : ops){
            modify(p.F, p.S);
        }
        vector<pii>().swap(ops);
    }
} bit;


void cdq(vector<Obj> &v){
    cout << "cdq of " << v.size() << endl;
    if(v.size() <= 1) return;
    vector<Obj> lft, rgt;
    for(int i = 0; i < v.size(); i++){
        v[i].tag = !(i < v.size() / 2); //0 for left, 1 for right
        (i < v.size() / 2 ? lft : rgt).push_back(v[i]);
    }
    cdq(lft);
    cdq(rgt);
    sort(v.begin(), v.end(), [](const Obj a, const Obj b){
        if(a.x == b.x) return a.type > b.type; //MODIFY FIRST
        else return a.x < b.x;
    });
    for(Obj o : v){
        cout << "Looking at x = " << o.x << ", y = " << o.y << ", time = " << o.t << ", type = " << o.type << endl;
        if(o.tag == 0){ //MODIFY
            if(o.type) continue;
            bit.modify(o.y, 1);
        } else {
            if(!o.type) continue;
            ans[o.id] += bit.query(o.y);
        }
    }
    //undo
    bit.undo();
}

int main(){
    ericxiao;
    cin >> N;
    int qc = 0;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c; //remember to lisan
        lisx.emplace_back(b);
        lisy.emplace_back(c);
        all.emplace_back(b, c, i, a, qc);
        if(!a) qc++;
    }
    sort(lisx.begin(), lisx.end());
    sort(lisy.begin(), lisy.end());
    for(int i = 0; i < N; i++){
        cout << "Original x y = " << all[i].x << ", " << all[i].y << endl;
        all[i].x = upper_bound(lisx.begin(), lisx.end(), all[i].x) - lisx.begin();
        all[i].y = upper_bound(lisy.begin(), lisy.end(), all[i].y) - lisy.begin();
        cout << "New x y = " << all[i].x << ", " << all[i].y << endl;
    }
    sort(all.begin(), all.end(), [=](Obj &a, Obj &b){
        return a.t < b.t;
    });
    cdq(all);
    for(int i = 0; i < N; i++){
        all[i].x = N - all[i].x + 1;
        all[i].y = N - all[i].y + 1;
    }
    for(int i = 0; i < qc; i++) cout << ans[i] << '\n';

}
