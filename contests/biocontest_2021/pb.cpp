#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e4 + 326, INF = 2e10 + 326;

int m[maxN], a[maxN];
string s;

struct Obj{
    int s, x, y;
    Obj(){}
    Obj(int _s, int _x, int _y): s(_s), x(_x), y(_y){}
    bool operator<(const Obj &o) const {
        return s < o.s;
    }
};

vector<Obj> vec;

int parse(string s){
    return stoi(s.substr(0, s.length() - 7) + s.substr(s.length() - 6, s.length()));
}

inline int Abs(int x){
    return x < 0 ? -x : x;
}

inline void solve(){
    int N, M, Q, que;
    cin >> N >> M >> Q;
    for(int i = 0; i < N; i++){
        cin >> s;
        m[i] = parse(s);
    }
    for(int i = 0; i < M; i++){
        cin >> s;
        a[i] = parse(s);
    }
    vector<Obj>().swap(vec);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(m[i] + a[j] > 0)
                vec.emplace_back(m[i] + a[j], i + 1, j + 1);
        }
    }
    vec.emplace_back(INF, -1, -1);
    vec.emplace_back(-INF, -1, -1);
    sort(vec.begin(), vec.end());
    Obj ans;
    while(Q--){
        cin >> s;
        que = parse(s);
        auto it = lower_bound(vec.begin(), vec.end(), que, [](const Obj o, const int x){
            return o.s < x;
        });
        ans = (Abs(it->s - que) < Abs(prev(it)->s - que)) ? *it : *(prev(it));
        cout << ans.x << " " << ans.y << endl;
    }
}


signed main(){
    ericxiao
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}

