#include <iostream>
#include <list>
#include <vector>
#include <deque>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std; //this solution is faster

const int blockSize = 500, maxN = 1e5 + 10;
deque<int> block[maxN];
int frqs[maxN/blockSize + 10][maxN];
int N, a, lastans = 0, c, l, r, k, q, com, blocknum;

inline void redo(){
    vector<int> vals;
    for(int i = 0; i < blocknum; i++){
        while(block[i].size()){
            vals.push_back(block[i].front());
            frqs[i][block[i].front()]--;
            block[i].pop_front();
        }
    }
    for(int i = 0; i < N; i++){
        block[i/blockSize].push_back(vals[i]);
        frqs[i/blockSize][vals[i]]++;
    }
}

inline void cyc(int l, int r){
    int b = 0, k = 0;
    for(b = 0; b < blocknum; b++){
        if(k + block[b].size() > r) break;
        k += block[b].size();
    }
    int rval;
    auto it = block[b].begin();
    for(int i = 0; i < r - k; i++) it = next(it);
    //cout << b << " th block" << endl;
    rval = *it;
    block[b].erase(it);
    frqs[b][rval]--;
    k = 0;
    for(b = 0; b < blocknum; b++){
        if(k + block[b].size() > l) break;
        k += block[b].size();
    }
    it = block[b].begin();
    for(int i = 0; i < l - k; i++) it = next(it);
    block[b].insert(it, rval);
    frqs[b][rval]++;
}

inline int getFrq(int l, int r, int k){
    //cout << "Running getfrq(" << l << ", " <<r << ", " << k << ")" << endl;
    int sl = 0, sr = 0, bl, br, ans = 0;
    for(bl = 0; bl < blocknum; bl++){
        if(sl + block[bl].size() > l) break;
        sl += block[bl].size();
    }
    for(br = 0; br < blocknum; br++){
        if(sr + block[br].size() > r) break;
        sr += block[br].size();
    }

    for(int i = bl + 1; i < br; i++) ans += frqs[i][k];
    int cnt = sl; //cnt: index of the first one
    //cout << "Starting: " << cnt << endl;
    for(int i : block[bl]){
        if(cnt >= l && cnt <= r){
            ans += (i == k);
            //cout << "Looking at " << i << endl;
        }
        cnt++;
    }
    if(bl != br){
        cnt = sr;
        //cout << "Starting: " << cnt << endl;
        for(int i : block[br]){
            if(cnt >= l && cnt <= r){
                ans += (i == k);
                //cout << "Looking at " << i << endl;
            }
            //cout << "Looking at " << i << endl;
            cnt++;
        }
    }

    return ans;
}

inline void disp(){
    for(int i = 0; i < blocknum; i++){
        for(int u : block[i]) cout << u << " ";
    }
    cout << endl;
}

signed main(){
    ericxiao;
    cin >> N;
    blocknum = (N + blockSize - 1) / blockSize;
    for(int i = 0; i < N; i++){
        cin >> a;
        a--;
        block[i/blockSize].push_back(a);
        frqs[i/blockSize][a]++;
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> com >> l >> r;
        l = (l + lastans - 1 + 10 * N) % N;
        r = (r + lastans - 1 + 10 * N) % N;
        if(l > r) swap(l, r);
        if(com == 1){
            //cout << "Cycling " << l << " to " <<r << endl;
            cyc(l, r);
            //disp();
        } else if(com == 2) {
            cin >> k;
            k = (k + lastans - 1 + 10 * N) % N;
            lastans = getFrq(l, r, k);
            cout << lastans << endl;
        }
        if(i && !(i % (blockSize))) redo();
    }
}
