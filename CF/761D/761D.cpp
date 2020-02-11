#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, l, r;
vector<int> a, b, p, ord;

int main(){
    ericxiao;
    cin >> n >> l >> r;
    a.resize(n);
    b.resize(n);
    p.resize(n);
    ord.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    //
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [](int i, int j){
        return p[i] > p[j];
    });
    b[ ord[0] ] = r;
    int currentval = r - a[ ord[0] ];
    for(int i = 1; i < n; i++){
        //cout << "Looking now at " << ord[i] << endl;
        //b - a[ord[i]] < currentval
        //b is at most min((currentval + a[ ord[i] ] - 1), r)
        b[ ord[i] ] = min((currentval + a[ ord[i] ] - 1), r);
        if(b[ord[i]] < l){
            cout << -1 << endl;
            return 0;
        }
        currentval = b[ord[i]] - a[ ord[i] ];
        //
    }
    //3 4 8 9
    //2 2 5 9
    //-1 -2 -3 0
    for(int i : b){
        cout << i << " ";
    }
    cout << endl;
}
