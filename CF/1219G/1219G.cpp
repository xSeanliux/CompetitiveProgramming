#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 1e5 + 10, INF = 1e18;

int n, m, ans = 0;
vector<int> arr[maxN];

inline int getAns(){
    int mx = -INF, id = -1, cs;
    bool iscol = false;
    for(int i = 0; i < n; i++){
        cs = 0;
        for(int j = 0; j < m; j++){
            cs += arr[i][j];
        }
        if(cs > mx){
            id = i;
            mx = cs;
        }
    }
    for(int i = 0; i < m; i++){
        cs = 0;
        for(int j = 0; j < n; j++){
            cs += arr[j][i];
        }
        if(cs > mx){
            id = i;
            mx = cs;
            iscol = true;
        }
    }
    if(iscol){
        for(int i = 0; i < n; i++) arr[i][id] = 0;
    } else {
        for(int i = 0; i < m; i++) arr[id][i] = 0;
    }
    return mx;
}


signed main(){
    ericxiao;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        arr[i].resize(m);
        for(int j = 0; j < m; j++) cin >> arr[i][j];
    }
    for(int i = 0; i < 4; i++) ans += getAns();
    cout << ans << endl;
}
