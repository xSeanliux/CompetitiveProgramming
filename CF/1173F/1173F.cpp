#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> pii;

const int maxN = 1e3;
int goH[maxN + 10], goV[maxN + 10], fromH[maxN + 10], fromV[maxN + 10], N;
vector<pii> ans;

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> goH[i];
        fromH[goH[i]] = i;
    }

    for(int i = 1; i <= N; i++){
        cin >> goV[i];
        fromV[goV[i]] = i;
    }
    int fv, fh;
    for(int i = 1; i <= N; i++){
        fv = fromV[i], fh = fromH[i]; //want to put in (i,fv), (fh,i)
        if(fv == i && fh == i) continue; //don't need to place anything here
        ans.push_back({i, fv}), ans.push_back({fh, i});
        goV[fv] = goV[i];
        fromV[goV[i]] = fv;
        goH[fh] = goH[i];
        fromH[goH[i]] = fh;
    }
    cout << ans.size()/2 << endl;
    if(!ans.size()) return 0;
    for(int i = 0; i < ans.size() - 1; i += 2){
        cout << ans[i].first << " " << ans[i].second << " " << ans[i + 1].first << " " << ans[i + 1].second << endl;
    }
}
