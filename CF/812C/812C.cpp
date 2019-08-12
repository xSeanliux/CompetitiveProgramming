#include <iostream>
#include <algorithm>
#include <vector>
#define int long long int
using namespace std;

int N, S, k, a, b;

struct Obj{
    int val, ind;
    Obj(){};
    Obj(int val, int ind): val(val), ind(ind){}
};

vector<Obj> vec;

bool cmp(const Obj a, const Obj b) {
    return a.val + a.ind * k < b.val + b.ind * k;
}

int canDo(int len){
    //cout << "Running cando(" << len << ")" << endl;
    k = len;
    sort(vec.begin(), vec.end(), cmp);
    int cost = 0;
    for(int i = 0; i < len; i++){
        //printf("Choosing ind = %d, ind = %d, val = %d, k = %d\n", vec[i].ind, vec[i].ind, vec[i].val, len);
        cost += vec[i].val + vec[i].ind * k;
    }
    //printf("cost(%d) = %d\n", len, cost);
    return (cost <= S ? cost : -1);
}

signed main(){
    cin >> N >> S;
    for(int i = 1; i <= N; i++){
        cin >> a;
        vec.push_back(Obj(a, i));
    }
    int l = 0, r = N + 1, m = l + r >> 1;
    while(l + 1 < r){
        if(canDo(m) > -1){
            l = m;
        } else {
            r = m;
        }
        m = l + r >> 1;
    }
    for(int i = min((int)m, N); i >= max(0LL, m - 1); i--){
        if(canDo((int)m) > -1){
            cout << m << " " << canDo(m) << endl;
            return 0;
        }
    }
}
