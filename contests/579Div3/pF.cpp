#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;


vector<pii> badd, bsub;

int n, r, a, b;

int main(){
    cin >> n >> r;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(b >= 0){
            badd.push_back({a, b});
        } else {
            bsub.push_back({a, b});
        }
    }
    sort(badd.begin(), badd.end());
    for(auto p : badd){
        if(p.F > r){
            cout << "NO" << endl;
            return 0;
        } else {
            r += p.S;
        }
    }
    cout << "YES" << endl;
    /*
    sort(bsub.begin(), bsub.end(), [](pii a, pii b){
        return a.S > b.S;
    });
    bool cando = true;
    for(auto p : bsub){
        if(p.F > r){
            //cout << "NO" << endl;
            cando = false;
            break;
            //return 0;
        } else {
            r += p.S;
            if(r < 0){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    */
}

