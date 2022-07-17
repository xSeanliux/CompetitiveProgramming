#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 326;
int N, arr[maxN], Q, ans[maxN],curMax = -1;
bool hasPut[maxN];

struct Obj{
    int t, p, x;
    Obj(){}
    Obj(int t, int p, int x): t(t), p(p), x(x){}
};

vector<Obj> ops;


int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cin >> Q;
    int com, p, x;
    while(Q--){
        cin >> com;
        if(com == 1){
            cin >> p >> x;
            p--;
            ops.emplace_back(com, p, x);
        } else { //payout of x
            cin >> x;
            ops.emplace_back(com, -1, x);
        }
    }
    reverse(ops.begin(), ops.end());
    for(auto op : ops){
        if(op.t == 1){
            if(hasPut[op.p]) continue;
            ans[op.p] = max(op.x, curMax);
            hasPut[op.p] = true;
        } else {
            curMax = max(curMax, op.x);
        }
    }
    for(int i = 0; i < N; i++){
        if(!hasPut[i]){
            ans[i] = max(curMax, arr[i]);
        }
    }
    for(int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
}
