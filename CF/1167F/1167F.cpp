#include <iostream>
#include <algorithm>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 5e5 + 10, MOD = 1e9 + 7;

int n, sz, ans = 0;
vector<int> lis, inv, vec, lef, rig;

int add(int a, int b){return (a + b) % MOD;}
int sub(int a, int b){return (a - b + MOD) % MOD;};
int mult(int a, int b){return (a * b) % MOD; };

struct BIT{
    int arr[maxN];
    BIT(){
        fill(arr, arr + maxN, 0);
    }
    void modify(int p, int x){
        while(p < maxN){
            arr[p] = add(arr[p], x);
            p += (p & -p);
        }
    }
    int query(int p){
        int res = 0;
        while(p  > 0){
            res = add(res, arr[p]);
            p -= (p & -p);
        }
        return res;
    }
} lbit, rbit;

signed main(){
    ericxiao;
    cin >> n;
    vec.resize(n + 1);
    lef.resize(n + 1);
    rig.resize(n + 1);
    inv.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> vec[i];
        lis.push_back(vec[i]);
    }
    sort(lis.begin(), lis.end());
    sz = unique(lis.begin(), lis.end()) - lis.begin();
    for(int i = 1; i <= n; i++){
        vec[i] = upper_bound(lis.begin(), lis.begin() + sz, vec[i]) - lis.begin();

    }
    //cout << endl;

    for(int i = 1; i <= sz; i++){
        inv[i] = lis[i - 1];
    }
    for(int i = 1; i <= n; i++){
        lbit.modify(vec[i], i);
        lef[i] = lbit.query(vec[i]);
    }
    reverse(vec.begin(), vec.end());
    for(int i = 0; i < n; i++){
        rbit.modify(vec[i], i + 1);
        rig[n - i] = rbit.query(vec[i]);
    }
    reverse(vec.begin(), vec.end());
    int ans = 0, tw;
    for(int i = 1; i <= n; i++){
        tw = 0;
        tw = add(tw, mult(n - i + 1, lef[i]));
        tw = sub(tw, mult(i, n - i + 1));
        tw = add(tw, mult(i, rig[i]));
        ans = add(ans, mult(tw, inv[vec[i]]));
    }
    cout << ans << endl;

}



