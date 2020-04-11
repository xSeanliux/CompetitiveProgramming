#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e5 + 226, LIM = 226;

struct Com{
    int a, l;
};

int N, K, a, d, l, ans[maxN], pre[LIM][maxN], modgo[LIM];

int main(){
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        cin >> a >> l >> d;
        a--;
        if(d >= LIM){
            for(int p = 0; p < l; p++) ans[a + p * d]++;
        } else {
            pre[d][a]++;
            pre[d][a + l * d]--;
        }
    }
    for(int d = 1; d < LIM; d++){
        fill(modgo, modgo + d, 0);
        for(int i = 0; i < N; i++){
            modgo[i % d] += pre[d][i];
            ans[i] += modgo[i % d];
        }
    }
    for(int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
}
