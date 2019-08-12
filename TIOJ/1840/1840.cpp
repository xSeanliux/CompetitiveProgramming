#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 50000, MAXQ = 10000;

struct OP{
    int l, r, k, ans;
    /*
    If it's a query:
        search kth in [l, r]
    Else if it's a modify
        l == -1: Add k at r
        l == -2: Remove k at r
    */
} ops[MAXN + 2 * MAXQ + 10];

int n, q, com, arg1, arg2, arg3, arr[MAXN + 10], bit[MAXN + 10], t;
vector<int> p;

inline void add(int x, int p){
    for(; p <= n; p += (p & -p)) bit[p] += x;
}

inline int sum(int p){
    int res = 0;
    for(; p; p -= (p & -p)) res += bit[p];
    return res;
}


/*
0 1 2 3 4 5
2 3 5 6 7 8

2 3 8 6 7
0 1 5 3 4

*/
void do_ops(int mid, vector<int>& VS, int type, bool modify){
    for(int i : VS){
        if(ops[i].l == -1){ //Add
            if(ops[i].k <= mid) add(type, ops[i].r);
        } else if(ops[i].l == -2){ //Remove
            if(ops[i].k <= mid) add(-type, ops[i].r);
        } else if(modify){
            ops[i].ans = sum(ops[i].r) - sum(ops[i].l - 1);
            //printf("ops[%d].ans = %d\n", i, ops[i].ans);
        }
    }
}

void divide(int mid, vector<int>& VS, vector<int>& LS, vector<int>& RS){
    for(int i : VS){
        if(ops[i].l < 0 && ops[i].l != -3){ //modify
            if(ops[i].k <= mid) LS.emplace_back(i);
            else RS.emplace_back(i);
        } else { //query
            if(ops[i].ans >= ops[i].k) LS.emplace_back(i);
            else {
                RS.emplace_back(i);
                ops[i].k -= ops[i].ans;
            }
        }
    }
    vector<int>().swap(VS); //empty VS
}

void total_bs(int l, int r, vector<int>& VS){ //lol
    if(!VS.size()) return;
    //printf("Running BS(%d, %d)\n", l, r);
    if(l == r){
        for(int i : VS) ops[i].ans = l;
        return;
    }
    int mid = l + r >> 1;
    vector<int> LS, RS;
    do_ops(mid, VS, 1, true);
    divide(mid, VS, LS, RS);
    do_ops(mid, LS, -1, false);
    //for the above line, if divide() has a VS.clear() (or vector<int>().swap(VS)),
    //then you need to use do_ops(mid, LS, -1, false) to undo the operations done
    //since every operation you did will be put in LS anyway, undo using it will be
    //fine.

    total_bs(l, mid, LS);
    total_bs(mid + 1, r, RS);
}


int main(){
    scanf("%d", &t);
    while(t--){
        p.clear();
        scanf("%d%d", &n, &q);
        int m = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", arr + i);
            ops[m++] = {-1, i, arr[i], 0};
            p.emplace_back(arr[i]);
        }
        for(int i = 1; i <= q; i++){
            scanf("%d", &com);
            if(com == 1){
                scanf("%d%d%d", &arg1, &arg2, &arg3);
                ops[m++] = {arg1, arg2, arg3, 0};
            } else if(com == 2) {
                scanf("%d%d", &arg1, &arg2);
                ops[m++] = {-2, arg1, arr[arg1], 0};
                ops[m++] = {-1, arg1, arg2, 0};
                p.emplace_back(arr[arg1] = arg2);
            } else {
                scanf("%d%d", &arg1, &arg2);
                ops[m++] = {-3, arg1, arg2, 69};
            }
        }
        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
        vector<int> VS; //stores the indices of the operations
        for(int i = 0; i < n ; i++) bit[i] = 0;
        for(int i = 0; i < m; i++){
            if(ops[i].l == -3) continue;
            if(ops[i].l < 0){
                ops[i].k = lower_bound(p.begin(), p.end(), ops[i].k) - p.begin();
                //cout << "OPS[" << i << "].k = " << ops[i].k << endl;
            }
            VS.emplace_back(i);
        }
        total_bs(0, p.size(), VS);
        for(int i = n; i < m; i++){
            if(ops[i].l == -3) printf("7122\n");
            if(ops[i].l > 0) printf("%d\n", p[ops[i].ans]);
        }
    }
}
