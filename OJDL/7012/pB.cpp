#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int q, n, r;
vector<int> v;

int main(){
    ericxiao;
    cin >> q;
    while(q--){
        cin >> n >> r;
        v.resize(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int tkm = 0, last = -1;
        for(int i : v){
            if(last == i) continue;
            last = i;
            //cout << i << ", tkm = " << tkm << endl;
            if(i <= tkm) continue;
            else tkm += r;
        }
        cout << tkm / r << endl;
    }
}


