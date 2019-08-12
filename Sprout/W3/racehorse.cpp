#include <iostream>
#include <algorithm>
#include <vector>
#define lld long long int
using namespace std;

lld T, N, K;
lld _a, _b, _c;

bool canWin(vector<lld> a, vector<lld> b, vector<lld> c, lld day){
    vector<lld> v;
    v.clear();
    v.resize(N);
    for(int i = 0; i < N; i++){
        v[i] = a[i] + b[i] * day;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < K; i++){
        if(v[N - K + i] <= c[i]) return false;
    }
    return true;
}

int main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        vector<lld> a = vector<lld>(N), b = vector<lld>(N), c = vector<lld>(N);
        for(int i = 0; i < N; i++){
            cin >> _a >> _b;
            a[i] = _a; b[i] = _b;
        }
        for(int i = 0; i < N; i++){
            cin >> _c;
            c[i] = _c;
        }
        sort(c.begin(), c.end());
        lld l = -1, r = 1e9, mid = l + r >> 1;
        while(r - l > 1){
            if(canWin(a, b, c, mid)){
                r = mid;
            } else {
                l = mid;
            }
            mid = l + r >> 1;
        }
        if(mid > (lld)1e8) cout << -1 << endl;
        else cout << mid + 1 << endl;
    }
}
