#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxN = 100, INF = 1e7;

vector<int> prices;
int T, ans[maxN][maxN], val[maxN][maxN], N, P, K;

int run(int stk, int toTake){
    if(ans[stk][toTake]){
        return ans[stk][toTake];
    }
    if(!stk){
        if(toTake > K) ans[stk][toTake] = -INF;
        else for(int i = 0; i < min(K, toTake); i++) ans[stk][toTake] += val[0][i];
		return ans[stk][toTake];
    }
    ans[stk][toTake] = run(stk - 1, toTake);
    int pre = 0;
    for(int i = 0; i < min(K, toTake); i++){
        pre += val[stk][i];
        ans[stk][toTake] = max(ans[stk][toTake], pre + run(stk - 1, toTake - i - 1));
    }
    return ans[stk][toTake];
}

int main(){
    cin >> T;
    int c = 0;
    while(T--){
        cin >> N >> K >> P;
        for(int i = 0; i < N; i++)
            for(int j = 0; j <= P; j++)
                ans[i][j] = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < K; j++)
                cin >> val[i][j];
        cout << "Case #" << ++c << ": " <<  run(N - 1, P) << endl;
    }
}
