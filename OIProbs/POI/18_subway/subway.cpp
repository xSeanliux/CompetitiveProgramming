#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <numeric>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long int
using namespace std;

const int maxN = 1e6 + 26;

int N, a[maxN], b[maxN], ord[maxN];
map<int, int> cha;
inline int Abs(int x){
    return (x < 0 ? -x : x);
}

struct Edge{
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w){}
};

vector<Edge> edges;


signed main(){
    ericxiao;
    cin >> N;
    if(N == 1){
        cout << "TAK" << endl;
        return 0;
    }
    if(N == 2){
        cout << "TAK" << endl;
        cout << "1 2 7122\n";
        return 0;
    }
    for(int i = 2; i <= N - 1; i++) cin >> a[i];
    for(int i = 2; i <= N - 1; i++) cin >> b[i];
    bool f = true;
    for(int i = 2; i <= N - 1; i++){
        if(Abs(a[i] - b[i]) != Abs(a[2] - b[2])){
            f = false;
            break;
        }
    }
    if(f && Abs(a[2] - b[2]) != 0){
        cout << "TAK" << endl;
        cout << 1 << " " << N << " " << Abs(a[2] - b[2]) << endl;
        for(int i = 2; i <= N - 1; i++){
            if(a[i] > b[i]){
                cout << N << " " << i << " " << b[i] << endl;
            } else {
                cout << 1 << " " << i << " " << a[i] << endl;
            }
        }
        return 0;
    }
    iota(ord, ord + N - 2, 2);
    sort(ord, ord + N - 2, [=](int i, int j){
        if(a[i] + b[i] == a[j] + b[j]){
            return a[i] < a[j];
        } else {
            return (a[i] + b[i]) < (a[j] + b[j]);
        }
    });
    cha[-(a[ord[0]] + b[ord[0]])] = 1;
    cha[(a[ord[0]] + b[ord[0]])] = N;
    int last = 1;
    for(int i = 0; i < N - 2; i++){
        if(a[ord[i]] + b[ord[i]] == a[ord[0]] + b[ord[0]]){
            if(i && a[ord[i]] == a[ord[i - 1]]){
                cout << "NIE" << endl;
                return 0;
            }
            edges.emplace_back(last, ord[i], a[ord[i]] - a[ord[i - 1]]);
            last = ord[i];
            cha[a[ord[i]] - b[ord[i]]] = ord[i];
        } else {
            if(!cha.count(a[ord[i]] - b[ord[i]])){
                cout << "NIE" << endl;
                return 0;
            }
            if(a[cha[a[ord[i]] - b[ord[i]]]] - a[ord[i]] == 0){
                cout << "NIE" << endl;
                return 0;
            }
            if(cha[a[ord[i]] - b[ord[i]]] == 1){
                edges.emplace_back(1, ord[i], a[ord[i]]);
            } else if(cha[a[ord[i]] - b[ord[i]]] == N){
                edges.emplace_back(N, ord[i], b[ord[i]]);
            } else edges.emplace_back(cha[a[ord[i]] - b[ord[i]]], ord[i], Abs(a[ord[i]] - a[cha[a[ord[i]] - b[ord[i]]]]));
        }
    }
    edges.emplace_back(last, N, b[last]);

    cout << "TAK" << endl;
    for(auto e : edges){
        cout << e.u << " " << e.v << " " << e.w << endl;
    }
}


