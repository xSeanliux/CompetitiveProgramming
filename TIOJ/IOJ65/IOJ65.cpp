#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, M, x;
map<int, int> frqs;
vector<int> pre;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    pre.resize(N);
    cin >> pre[0];
    frqs[0] = -1;
    frqs[pre[0] % M] = 0;
    if(pre[0] % M == 0){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1; i < N; i++){
        cin >> pre[i];
        pre[i] += pre[i - 1];
        pre[i] %= M;
        if(frqs.count(pre[i])){
            cout << i - frqs[pre[i]] << endl;
            for(int j = max(frqs[pre[i]] + 1, 0); j <= i; j++){
                cout << j + 1 << " \n"[j == i];
            }
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
