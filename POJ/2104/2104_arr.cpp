#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int maxm = 3e6;
const int maxn = 1e5 + 10;
const int L = 0;
const int R = maxn;

int arr[maxn], lis[maxn], inv[maxn], n, m, l, r, k;

struct node{
    int v, l, r;
}__ptr[maxm];
int &left(int i){
    return __ptr[i].l;
}
int &right(int i){
    return __ptr[i].r;
}
int &sum(int i){
    return __ptr[i].v;
}
int new_node(){
    static int mem = 0;
    return ++mem;
}
int root[maxn];
int insert(int oroot, int pos, int val){
    int mid, l = L, r = R;
    int newroot = new_node(), cur = newroot;
    while(l < r){
        mid = (l+r)>>1;
        if(pos <= mid){
            right(cur) = right(oroot);
            left(cur) = new_node();
            __ptr[left(cur)] = __ptr[left(oroot)];
            sum(left(cur)) += val;
            cur = left(cur), oroot = left(oroot);
            r = mid;
        }
        else{
            left(cur) = left(oroot);
            right(cur) = new_node();
            __ptr[right(cur)] = __ptr[right(oroot)];
            sum(right(cur)) += val;
            cur = right(cur), oroot = right(oroot);
            l = mid+1;
        }
    }
    return newroot;
}
int query(int lnow, int rnow, int k){
    int l = L, r = R, m, v;
    while(l < r){
        m = (l + r) / 2;
        v = sum(left(rnow)) - sum(left(lnow));
        if(v >= k){
            r = m;
            lnow = left(lnow);
            rnow = left(rnow);
        } else {
            k -= v;
            l = m + 1;
            lnow = right(lnow);
            rnow = right(rnow);
        }
    }
    return lis[l];
}

signed main(){
    ericxiao;
    __ptr[0] = {0,0,0};
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        lis[i-1] = arr[i];
    }
    sort(lis, lis + n), r;
    for(int i = 1; i <= n; i++){
        r = lower_bound(lis, lis + n, arr[i]) - lis;
        arr[i] = r;
        root[i] = insert(root[i - 1], arr[i], 1);
    }
    for(int i = 0; i < m; i++){
        cin >> l >> r >> k;
        cout << query(root[l - 1], root[r], k) << '\n';
    }

}
