#include <iostream>
#include <vector>
using namespace std;

vector<int> vec, pre;
int N, S, x, ans;

int main(){
    while(cin >> N >> S){
        ans = N + 1;
        vec.resize(N); pre.resize(N);
        cin >> vec[0];
        pre[0] = vec[0];
        for(int i = 1; i < N; i++){
            cin >> vec[i];
            pre[i] = pre[i-1] + vec[i];
        }
        for(int i = 0; i < N; i++){
            auto it = lower_bound(pre.begin(), pre.end(), pre[i] + S);
            if(it != pre.end()){
                ans = min(ans, (int)(it - pre.begin() - i));
            }
        }
        if(ans <= N) cout << ans << endl;
        else cout << 0 << endl;
    }
}
