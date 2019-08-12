#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

map<int, int> ID;
vector<int> arr, _a, ans, freqs;
int N, M, l, r, c = 0, bS, currentAns = 0;

struct Query{
    int l, r, id;
    Query(){}
    Query(int l, int r): l(l), r(r), id(c++){}
    bool operator<(const Query q) const {
        return l/bS < q.l/bS || (l/bS == q.l/bS && r < q.r);
        //return (l/bS) ^ (q.l/bS) ? l < q.l : ( l/bS & 1 ? r < q.r : r > q.r);
    }
};

void update(int x, int d){
    currentAns += (freqs[x] + d == x) - (freqs[x] == x);
    freqs[x] += d;
}

vector<Query> qs;

int main(){
    ericxiao
    cin >> N >> M;
    bS = sqrt(M*2/3*1.0);
    arr.resize(N);
    _a.resize(N);
    ans.resize(M);
    qs.resize(M);
    freqs.resize(N + 1);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(arr[i] > N) arr[i] = -1;
    }

    for(int i = 0; i < M; i++){
        cin >> l >> r;
        qs[i] = Query(l - 1, r - 1);
    }
    sort(qs.begin(), qs.end());
    int L = 1, R = 0;
    currentAns = 0;
    for(int i = 0; i < M; i++){
        while(L > qs[i].l){
            update(arr[--L], 1);
        }
        while(R < qs[i].r){
            update(arr[++R], 1);
        }
        while(L < qs[i].l){
            update(arr[L++], -1);
        }
        while(R > qs[i].r){
            update(arr[R--], -1);
        }
        ans[qs[i].id] = currentAns;
    }
    for(int i : ans) cout << i << endl;
}

