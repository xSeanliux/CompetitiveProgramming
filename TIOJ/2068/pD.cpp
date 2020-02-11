#include <iostream>
#include <numeric>
#include <vector>
#include <utility>
#define pii pair<int,int>
#include <set>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int maxN = 5e5 + 20;

vector<pii> segs;


class Cmp{
public:
    bool operator()(int i, int j) const {
        return segs[i].S < segs[j].S;
    }
};

set<int, Cmp> currentIn;
int N, arr[maxN * 2], l, r;



struct DSU{
    int N, d[maxN];
    DSU(){}
    DSU(int n): N(5 + n){
        iota(d, d + N, 0);
    }
    void Flat(int x){
        if(x == d[x]) return;
        Flat(d[x]);
        d[x] = d[d[x]];
    }
    bool Merge(int a, int b){
        Flat(a);
        Flat(b);
        if(d[a] == d[b]) return false;
        d[d[a]] = d[b];
        return true;
    }
} dsu;

int main(){
    ericxiao;
    cin >> N;
    dsu = DSU(N);
    segs.push_back({0, 0});
    for(int i = 1; i <= N; i++){
        cin >> l >> r;
        arr[l] = i;
        arr[r] = -i;
        segs.push_back({l, r});
    }
    int edges = 0, _l, _r;
    for(int i = 1; i <= 2 * N; i++){
        if(arr[i] < 0){
            //cout << "Erasing " << -arr[i] << endl;
            currentIn.erase(currentIn.find(-arr[i]));
        } else {
            //cout << "Looking at " << arr[i] << endl;
            for(int e : currentIn){
                //cout << "Connecting to " << e << endl;
                _r = segs[e].S;
                if(_r > segs[arr[i]].S) break;
                if(dsu.Merge(arr[i], e)){
                    edges++;
                    if(edges >= N){
                        cout << "NO" << endl;
                        return 0;
                    }
                } else {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            currentIn.insert(arr[i]);
        }
    }
    dsu.Flat(1);
    int root = dsu.d[1];
    for(int i = 2; i <= N; i++){
        dsu.Flat(i);
        if(dsu.d[i] != root){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
