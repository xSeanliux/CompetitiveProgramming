#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pii pair<int,int>
using namespace std;

map<int, int> frq;
vector<pii> vec;
int N, Q, x, q;

int main(){
    ericxiao;
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> x;
        frq[x]++;
    }
    for(auto p : frq){
        vec.push_back(p);
        //cout << "PUSHING: " << p.first << ", " << p.second << endl;
    }
    reverse(vec.begin(), vec.end());
    while(Q--){
        cin >> q;
        pii p;
        int c = 0;
        for(auto i : vec){
            //cout << "TRYING" << i.first << endl;
            //need: x/p.first
            c += min(i.second, q/i.first);
            q -= i.first * min(i.second, q/i.first);

            if(!q) break;
        }
        if(q > 0){
            cout << -1 << endl;
        } else {
            cout << c << endl;
        }
    }
}
