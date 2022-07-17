#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 326, INF = 2e10 + 326;

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
    map<int, int> pos = map<int, int>();
    for(int i = 0; i < N; i++){
        cin >> s;
        m[i] = parse(s);
        pos[m[i]] = i;
    }
    m[N] = INF;
    m[N + 1] = -INF;
    sort(m, m + N + 2);
    int _N = unique(m, m + N + 2) - m;
    N = _N;
    for(int i = 0; i < M; i++){
        cin >> s;
        a[i] = parse(s);
    }
    while(Q--){
        cin >> s;
        que = parse(s);
        int x = -1, y = -1, err = INF, j;
        for(int i = 0; i < M; i++){
           j = lower_bound(m, m + N, que - a[i]) - m;
           /*
           cout << "looking for " << que << endl;
           cout << "Found: " << m[j] << " " << a[i] << endl;
           if(j) cout << "And: " << m[j - 1] << " " << a[i] << endl;
           */
           if((m[j] + a[i] > 0) && (err > Abs(m[j] + a[i] - que))){
               y = i + 1;
               err = Abs(m[j] + a[i] - que);
               x = pos[m[j]] + 1;
           }
           if(j && (m[j - 1] + a[i] > 0) && (err > Abs(m[j - 1] + a[i] - que))){
               y = i + 1;
               err = Abs(m[j - 1] + a[i] - que);
               x = pos[m[j - 1]] + 1;
           }
        }
        cout << x << " " << y << endl;
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


