#include <iostream>
#include <set>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 50;
int N, K, arr1[maxN], arr2[maxN], pos1[maxN], pos2[maxN];

struct Seg{
    int l, r;
    Seg(){}
    Seg(int l, int r = -1): l(l), r(r){}
    bool operator<(const Seg &o) const {
        return l < o.l;
    }
};
set<Seg> st;


inline set<Seg>::iterator get(int p){
    auto it = st.lower_bound(Seg(p));
    if(it != st.end() && it->l == p) return it;
    it--;
    if(it->r <= p) return st.end();
    return it;
}

inline void Merge(int l, int r){
    auto il = get(l), ir = get(r);
    int L = il->l, R = ir->r;
    ir++;
    st.erase(il, ir);
    st.insert(Seg(L, R));
}

int main(){
    ericxiao;
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> arr1[i];
        pos1[ arr1[i] ] = i;
    }
    for(int i = 1; i <= N; i++){
        cin >> arr2[i];
        pos2[ i ] = pos1[ arr2[i] ];
    }
    for(int i = 1; i <= N; i++){
        arr2[i] = pos2[i];
    }
    int cMax[maxN], cMin[maxN];
    cMax[1] = arr2[1];
    for(int i = 2; i <= N; i++){
        cMax[i] = max(cMax[i - 1], arr2[i]);
    }
    for(int i = 1; i <= N; i++){
        st.insert(Seg(i, i + 1));
    }
    for(int i = 1; i <= N; i++){
        if(i > 1 && cMax[i - 1] > arr2[i]){
            Merge(arr2[i], cMax[i - 1]);
        }
    }

    if(st.size() < K){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int cnt = 0;
    char ans[maxN];
    for(Seg s : st){
        for(int i = s.l; i < s.r; i++){
            ans[ arr1[ i ] ] = (char)('a' + cnt);
        }
        if(cnt < K - 1){
            cnt++;
        }
    }
    for(int i = 1; i <= N; i++) cout << ans[i];
}
