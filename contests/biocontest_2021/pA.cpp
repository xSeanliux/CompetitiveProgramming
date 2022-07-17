#include <iostream>
#include <string.h>
#include <map>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 326, maxL = 1e4 + 326, M = 1e9 + 7, M2 = 1e7 + 9;
int N, L, T;
string s;
int hsh[maxL], p2[maxL], ans[maxL], hsh2[maxL], p22[maxL];

inline int add(int a, int b, int m){
    return (a + b >= m ? a + b - m : a + b);
}

void solve(){
    cin >> N >> L;
    fill(hsh, hsh + L, 0);
    fill(hsh2, hsh2 + L, 0);
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < L; j++){
            if(s[j] == '1'){
                hsh[j] = add(hsh[j], ((i + 1) % M) * p2[i] % M, M);
                hsh2[j] = add(hsh2[j], ((i + 1) % M2) * p22[i] % M2, M2);
            }
        }
    }
    for(int i = 0; i < L; i++) hsh[i] ^= hsh2[i];
    map<int, int> mp = map<int, int>();
    int cnt = 1;
    for(int i = 0; i < L; i++){
        if(!mp.count(hsh[i])) mp[hsh[i]] = cnt++;
        ans[i] = mp[hsh[i]];
    }
    cout << mp.size() << endl;
    for(int i = 0; i < L; i++) cout << ans[i] << " \n"[i == L - 1];
}

signed main(){
    ericxiao;
    cin >> T;
    p2[0] = 1;
    p22[0] = 1;
    for(int i = 1; i < maxL; i++) p2[i] = p2[i - 1] * 2 % M;
    for(int i = 1; i < maxL; i++) p22[i] = p22[i - 1] * 2 % M2;
    while(T--){
        solve();
    }
}
