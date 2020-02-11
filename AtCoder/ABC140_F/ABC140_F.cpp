#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

map<int, int> have, donthave;

bool iter(){
    map<int, int> tohave;
    for(pii p : have){
        //p.S instances of p.F
        //cout << p.S << " instances of " << p.F << endl;
        for(int i = 0; i < p.S; i++){
            auto it = donthave.lower_bound(p.F);
            if(it == donthave.begin()) return false;
            it = prev(it);
            tohave[it->F]++;
            donthave[it->F]--;
            if(!donthave[it->F]) donthave.erase(donthave.find(it->F));
            //cout << "Found: " << it->F << ", " << it->S << endl;
        }
    }
    for(pii p : tohave) have[p.F] += p.S;
    return true;
}

int N, x;

int main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < (1LL << N); i++){
        cin >> x;
        donthave[x]++;
    }
    int last = donthave.rbegin()->F;
    donthave.rbegin()->S--;
    if(!donthave.rbegin()->S){
        donthave.erase(--donthave.end());
    }
    //cout << "Last = " << last <<endl;
    have[last]++;
    for(int i = 0; i < N; i++){
        if(!iter()){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
