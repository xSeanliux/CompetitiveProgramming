#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#include <vector>
#define int long long int
using namespace std;

const int maxN = 5e5 + 10;

int N, M, a, b, bit[maxN << 2];
vector<int> perm, target;
bool is[maxN];
priority_queue<int, vector<int>, greater<int>> pq; //stores the positions of the -1

inline void sadd(int p, int x){
    for(;p <= N;p+=(p&-p)) bit[p] += x;
}

inline void add(int l, int r, int v){ //adds v to [l, r]
    sadd(l, v);
    sadd(r + 1, -v);
}

inline int query(int p){
    int r = 0;
    while(p){
        r += bit[p];
        p -= (p & -p);
    }
    return r;
}

signed main(){
    cin >> N >> M;
    perm.resize(N + 1);
    target.resize(N + 1);
    iota(perm.begin(), perm.end(), 0);
    fill(target.begin(), target.end(), -1);
    for(int i = 1; i <= N; i++) is[i] = false;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        target[b - 1] = a;
        is[a] = true;
    }
    for(int i = 1; i <= N; i++){
        sadd(i, 1);
    }
    for(int i = 1; i <= N; i++){
        if(!is[i]){
            pq.push(i);
            //cout << "pushing " << i << endl;
        }
    }
    int ans = 0, id, pos;
    for(int i = 0; i < N; i++){
        //cout << "Looking for " << target[i] << endl;
        if(target[i] == -1){
            id = pq.top();
            pq.pop();
        } else {
            id = target[i];
        }
        //cout << "ID = " << id << endl;
        pos = query(id);
        //cout << "IS AT POS = " << pos << endl;
        //cout << "Q" << endl;
        ans += pos - i - 1;
        add(1, id, 1);
        //cout << "A" << endl;
    }
    cout << ans << endl;
    /*
    for(int i = 0; i < N; i++){
        //cout << "Looking for " << target[i] << endl;
        for(int j = i; j < N; j++){
            //cout << "Looking at perm[" << j << "] = " << perm[j] << endl;
            if(target[i] == perm[j] || (target[i] == -1  && !is[perm[j]])){
                //cout << "Found: " << perm[j] << endl;
                for(int k = j - 1; k >= i; k--){
                    swap(perm[k], perm[k + 1]);
                    ans++;
                }
                //for(int u : perm) cout << u << " ";
                //cout << endl;
                break;
            }
        }
    }
    */
    //cout << ans << endl;
}
