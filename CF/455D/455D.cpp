#include <iostream>
#include <deque>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10, blocksz = 500;
int N, Q, a, cmd, l, r, k, lastans = 0, blocknum;

deque<int> blocks[maxN/blocksz + 5];
int frq[maxN/blocksz + 5][maxN];

inline void redo(){
    vector<int> vec;
    for(int i = 0; i < blocknum; i++){
        while(blocks[i].size()){
            vec.push_back(blocks[i].front());
            frq[i][blocks[i].front()]--;
            blocks[i].pop_front();
        }
    }
    for(int i = 0; i < N; i++){
        blocks[i/blocksz].push_back(vec[i]);
        frq[i/blocksz][vec[i]]++;
    }
}

inline void cyc(int l, int r){
    //if(l == r) return;
    int bl, br, sl = 0, sr = 0;
    for(br = 0; br < blocknum; br++){
        if(sr + blocks[br].size() > r) break;
        sr += blocks[br].size();
    }

    auto itr = blocks[br].begin();
    for(int i = 0; i < r - sr; i++) itr = next(itr);
    int rval = *itr;
    blocks[br].erase(itr);
    frq[br][rval]--;
    for(bl = 0; bl < blocknum; bl++){
        if(sl + blocks[bl].size() > l) break;
        sl += blocks[bl].size();
    }
    auto itl = blocks[bl].begin();

    for(int i = 0; i < l - sl; i++) itl = next(itl);
    blocks[bl].insert(itl, rval);
    frq[bl][rval]++;
}


inline int getCnt(int l, int r, int k){
    //cout << "l, r= " << l << ", " << r << endl;
    int br, bl, sl = 0, sr = 0, res = 0;
    for(bl = 0; bl < blocknum; bl++){
        if(sl + blocks[bl].size() > l) break;
        sl += blocks[bl].size();
    }
    for(br = 0; br < blocknum; br++){
        if(sr + blocks[br].size() > r) break;
        sr += blocks[br].size();
    }
    for(int i = bl + 1; i < br; i++) res += frq[i][k];

    int cnt = sl;
    //cout << "sl = " << sl << endl;
    for(int i : blocks[bl]){
        if(l <= cnt && cnt <= r){
            //cout << i << endl;
            res += (i == k);
        }
        cnt++;
    }
    if(bl != br){
        cnt = sr;
        for(int i : blocks[br]){
            if(l <= cnt && cnt <= r) res += (i == k);
            cnt++;
        }
    }
    return res;
}

int main(){
    ericxiao;
    cin >> N;
    blocknum = (N + blocksz - 1) / blocksz;
    for(int i = 0; i < N; i++){
        cin >> a;
        a--;
        blocks[i/blocksz].push_back(a);
        frq[i/blocksz][a]++;
    }

    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> cmd >> l >> r;
        l = (l + lastans - 1 + 10 * N) % N;
        r = (r + lastans - 1 + 10 * N) % N;
        if(l > r) swap(l, r);
        if(l > r) swap(l, r);
        if(cmd == 1){
            cyc(l, r);
        } else {
            cin >> k;
            k = (k + lastans - 1 + N) % N;
            lastans = getCnt(l, r, k);
            cout << lastans << endl;
        }
        if(i && !(i % (blocksz))) redo();
    }
}
