#include <iostream>
#include <algorithm>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 1e4 + 10;

int n, a, b, c, d, bit[maxN];

struct Seg{
    int co, fr, to;
    Seg(int a, int b, int c, int d){
        if(a > c) swap(a, c);
        if(b > d) swap(b, d);
        if(a == c){
            co = a;
            fr = b;
            to = d;
        } else {
            co = b;
            fr = a;
            to = c;
        }
    }
    Seg(int a, int b, int c): co(a), fr(b), to(c){}
    Seg(){}
    bool operator<(const Seg s) const {
        return co < s.co;
    }
};

struct Query{
    bool type;
    int c, x, y;
    Query(){}
    Query(int con, int t){ //top
        type = 0;
        c = con;
        x = t;
    }
    Query(int con, int s, int t){ //hor
        type = 1;
        c = con;
        x = s;
        y = t;
    }
    bool operator<(const Query q) const {
        return (c == q.c) ? type > q.type : c < q.c;
    }
};

inline void add(int p, int v){
    while(p <= maxN){
        //cout << " p = " << p << endl;
        bit[p] += v;
        p += (p & -p);
    }
}

inline int que(int p){
    int r = 0;
    while(p > 0){
        r += bit[p];
        p -= (p & -p);
        //cout << " p = " << p << endl;
    }
    return r;
}

vector<Seg> hor, ver;

signed main(){
    ericxiao;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c >> d;
        if(a > c) swap(a, c);
        if(b > d) swap(b, d);
        a += 5001;
        b += 5001;
        c += 5001;
        d += 5001;
        if(a == c){ //ver
            ver.push_back(Seg(a, b, d));
        } else { //hor
            hor.push_back(Seg(b, a, c));
        }
    }
    sort(hor.begin(), hor.end());
    //events:
    //1. query: found a horizontal line
    //2. found top of a good line
    //<>
    vector<Query> queries;
    int ans = 0, res;
    for(int i = 0; i < hor.size(); i++){
        //cout << "Looking at y = " << hor[i].co << ", from/to = " << hor[i].fr << "/" << hor[i].to << endl;
        queries.clear();
        fill(bit, bit + maxN, 0);
        for(int j = 0; j < ver.size(); j++){
            if(hor[i].fr <= ver[j].co && ver[j].co <= hor[i].to && ver[j].fr <= hor[i].co && hor[i].co <= ver[j].to){
                add(ver[j].co, 1);
                //cout << "Adding " << ver[j].co << endl;
                queries.push_back(Query(ver[j].to, ver[j].co));
            }
        }

        for(int j = i + 1; j < hor.size(); j++){
            queries.push_back(Query(hor[j].co, hor[j].fr, hor[j].to));
            //cout << "Adding line: y = " << hor[j].co << ", fr/to = " << hor[j].fr << "/" << hor[j].to << endl;
        }
        sort(queries.begin(), queries.end());
        for(Query q : queries){
            if(q.type == 0){ //top
                add(q.x, -1);
                //cout << "Deleting " << q.x << endl;
            } else if(q.type == 1) {
                res = que(q.y) - que(q.x - 1);
                //cout << "Querying " << q.y << " to " << q.x - 1 << endl;
                //cout << " = " << res << endl;
                ans += res * (res - 1) / 2;
            }
        }
    }
    cout << ans << endl;
}
