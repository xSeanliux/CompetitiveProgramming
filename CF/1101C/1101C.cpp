#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int t, n, a, b;
vector<int> ans;
vector<pair<pii, int> > segs;

int main(){
    ericxiao;
    cin >> t;
    while(t--){
        cin >> n;
        ans.resize(n);
        segs.resize(n);
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            segs[i] = {{a, b}, i};
        }
        sort(segs.begin(), segs.end());
        bool canDo = false;
        int mr = segs[0].F.S;
        for(int i = 1; i < n && !canDo; i++){
            if(mr < segs[i].F.F){
                for(int j = 0; j < n; j++) ans[segs[j].S] = 1 + (j < i);
                for(int u : ans) cout << u << " ";
                cout << endl;
                canDo = true;
                break;
            }
            mr = max(segs[i].F.S, mr);
        }
        if(!canDo) cout << -1 << endl;
    }
}
