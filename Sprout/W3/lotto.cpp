#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> v, ans;
bool f = false;

void dfs(int last, int iter){
    //cout << "Running dfs(" << last << ", " << iter << ")" << endl;
    if(iter == 6){
        for(int i = 0; i < 6; i++) cout << ans[i]  << ((i == 5) ? "" : " ");
        cout << endl; return;
    }
    for(int i = last + 1; i <= k + iter - 6; i++){
        ans[iter] = v[i];
        dfs(i, iter + 1);
    }
}

int main(){
    ans.reserve(6);
    while(cin >> k){
        if(!k) return 0;
        v.reserve(k);
        for(int i = 0; i < k; i++) cin >> v[i];
        if(f) cout << endl;
        else f = true;
        dfs(-1, 0);
    }
}
