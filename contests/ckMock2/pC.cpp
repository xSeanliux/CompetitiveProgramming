#include <iostream>
using namespace std;
int N, k, arr[100], maxAns = -2147483648;
bool want[100];

int gcd(int a, int b){
    if(!a) return 0;
    return(!b) ? a : gcd(b, a % b);
}

void dfs(int ite){
    if(ite == N){
        int removeCnt = 0;
        for(int i = 0 ; i < N; i++){
            removeCnt += !want[i];
        }
        if(removeCnt > k) return;
        /*
        for(int i = 0 ; i < N; i++){
            cout << want[i] << " ";
        }
        cout << endl;
        */
        int ans, i;
        for(i = 0; i < N; i++){
            if(want[i]){
                ans = arr[i];
                break;
            }
        }
        for(; i < N; i++){
            if(want[i]) ans = gcd(ans, arr[i]);
            if(!arr[i] && want[i]) {ans = 0; break;}
        }
        maxAns = max(ans, maxAns);
        return;
    }
    want[ite] = 0;
    dfs(ite+1);
    want[ite] = 1;
    dfs(ite+1);
}

int main(){
    cin >> N >> k;
    for(int i = 0 ; i < N; i++){
        cin >> arr[i];
    }
    dfs(0);
    cout << maxAns << endl;
}
