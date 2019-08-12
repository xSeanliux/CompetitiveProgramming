#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<int> vec;
vector<vector<pii> > ans;

int N, Q, l, r;

int lg(int x){
    for(int i = 0;; i++){
        if((1LL << i) > x) return i;
    }
    return 0;
}

int L(int x){
    for(int i = 0;; i++){
        if((1LL << i) == x) return i;
    }
    return 0;
}

int main(){
    ericxiao;
    cin >> N;
    vec.resize(N);
    int logN = lg(N);
    ans.resize(logN + 2);

    for(int i = 0; i <= logN; i++){
        ans[i].resize(N);
    }
    for(int i = 0; i < N; i++){
        cin >> vec[i];
        ans[0][i] = {vec[i], 0};
    }
    for(int i = 1; i < logN; i++){
        for(int j = (1LL << i) - 1; j < N; j++){
            ans[i][j] = {(ans[i-1][j - (1LL << (i - 1))].first + ans[i-1][j].first) % 10, ans[i-1][j - (1LL << (i - 1))].second + ans[i-1][j].second + (ans[i-1][j - (1LL << (i - 1))].first + ans[i-1][j].first >= 10)};
            //cout << "ANS with len " << (1LL << i) << " and ending at " << j << " is " << ans[i][j].second << endl;
        }
    }
    cin >> Q;
    while(Q--){
        cin >> l >> r;
        cout << ans[L(r - l + 1)][r - 1].second << '\n';
    }
}

