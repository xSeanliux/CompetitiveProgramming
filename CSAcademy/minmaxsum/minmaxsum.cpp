#include <iostream>
#include <queue>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 326, M = 1e9 + 7;

int N, arr[maxN], ans = 0, cnt[maxN], s1[maxN], s2[maxN], s3[maxN], s4[maxN];
//s1: sum 2^r
//s2: sum rmin * 2^r
//s3: sum rmax * 2^r
//s4: sum rmin * rmax * 2^r

inline int add(int a, int b){
    return a + b >= M ? a + b - M : a + b;
}

inline int mult(int a, int b, int c = 1, int d = 1){
    int r = a % M;
    r = r * b % M;
    r = r * c % M;
    r = r * d % M;
    return r;
}

inline int sub(int a, int b){
    return a >= b ? a - b : a - b + M;
}

void solve(int l = 0, int r = N){
    if(l == r) return;
    if(r - l == 1){
        ans = add(ans, mult(cnt[l], cnt[N - r], arr[l], arr[l]));
        return;
    }
    int m = (l + r) / 2;
    solve(l, m);
    solve(m, r);
    int lMax = 0, lMin = M, rMax = 0, rMin = M;
    s1[m - 1] = s2[m - 1] = s3[m - 1] = s4[m - 1] = 0;
    for(int i = m; i < r; i++){
        rMin = min(rMin, arr[i]);
        rMax = max(rMax, arr[i]);
        s1[i] = add(s1[i - 1], cnt[N - 1 - i]);
        s2[i] = add(s2[i - 1], cnt[N - 1 - i] * rMin % M);
        s3[i] = add(s3[i - 1], cnt[N - 1 - i] * rMax % M);
        s4[i] = add(s4[i - 1], mult(cnt[N - 1 - i], rMin, rMax));
    }
    int minPt = m - 1, maxPt = m - 1;
    for(int i = m - 1; i >= l; i--){
        lMin = min(lMin, arr[i]);
        lMax = max(lMax, arr[i]);
        while(minPt < (r - 1) && arr[minPt + 1] >= lMin) minPt++;
        while(maxPt < (r - 1) && arr[maxPt + 1] <= lMax) maxPt++;
        if(minPt < maxPt){
            ans = add(ans, mult(cnt[i], lMin, lMax, s1[minPt]));
            ans = add(ans, mult(cnt[i], lMax, sub(s2[maxPt], s2[minPt])));
            ans = add(ans, mult(cnt[i], sub(s4[r - 1], s4[maxPt])));
        } else {
            ans = add(ans, mult(cnt[i], lMin, lMax, s1[maxPt]));
            ans = add(ans, mult(cnt[i], lMin, sub(s3[minPt], s3[maxPt])));
            ans = add(ans, mult(cnt[i], sub(s4[r - 1], s4[minPt]))); 
        }
    }
}

signed main(){
    ericxiao
    cnt[0] = cnt[1] = 1;
    cin >> N;
    for(int i = 2; i < N; i++){
        cnt[i] = cnt[i - 1] * 2 % M;
    }
    for(int i = 0; i < N; i++) cin >> arr[i];
    solve();
    cout << ans << endl;
}
