#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5;

int bit[maxN + 10], arr[maxN + 10], ans[maxN + 10], N;

inline void mod(int p, int x){
    for(int i = p; i <= N; i += (i & -i)) bit[i] += x;
}

inline int get(int p){
    int res = 0;
    for(int i = p; i > 0; i -= (i & -i)) res += bit[i];
    return res;
}

inline int getpos(int val){
    int l = 1, r = N + 1, m = (l + r) / 2;
    while(l + 1 < r){
        if(get(m) > val){
            r = m;
        } else {
            l = m;
        }
        m = (l + r) / 2;
    }
    return l;
}

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++){
        mod(i + 1, i);
    }
    bit[1] = 0;
    for(int i = N - 1; i >= 0; i--){
        ans[i] = getpos(arr[i]);
        mod(ans[i] + 1, -ans[i]);
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << " ";
    }
}
