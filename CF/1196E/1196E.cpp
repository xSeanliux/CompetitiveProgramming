#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

int q, w, b;
vector<pii> whi, bla, vert;

int main(){
    ericxiao;
    cin >> q;
    while(q--){
        cin >> b >> w;
        vert.resize(0);
        whi.resize(0);
        bla.resize(0);
        //start from (1e7, 1e7)
        bla.push_back({1, 2});
        int i;
        for(i = 0; b > 0 || w > 0; i++){
            if(i % 2){ //i am black
                if(!b) break;
                vert.push_back({i + 2, 2});
                b--;
                whi.push_back({i + 2, 1});
                whi.push_back({i + 2, 3});
            } else {
                if(!w) break;
                vert.push_back({i + 2, 2});
                w--;
                bla.push_back({i + 2, 1});
                bla.push_back({i + 2, 3});
            }
        }
        (i % 2 ? bla : whi).push_back({2 + i, 2});
        if(b > w){
            if(bla.size() < b){
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            for(pii p : vert){
                cout << p.F << " " << p.S << endl;
            }
            for(int i = 0; i < b; i++){
                cout << bla[i].F << " " << bla[i].S << endl;
            }
            continue;
        }
        if(whi.size() < w){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for(pii p : vert){
            cout << p.F << " " << p.S << endl;
        }
        for(int i = 0; i < w; i++){
            cout << whi[i].F << " " << whi[i].S << endl;
        }
    }
}
