#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, x;
vector<int> S;
set<int> oris, xors;

int main(){
    cin >> n >> x;
    oris.insert(0); xors.insert(x);
    for(int i = 1; i< (1LL << n); i++){
        if(!oris.count(i) && !xors.count(i)){
            S.push_back(i);
            oris.insert(i);
            xors.insert(i ^ x);
        }
    }
    cout << S.size() << endl;
    if(!S.size()) return 0;
    cout << S[0];
    for(int i = 1; i < S.size(); i++){
        cout << " " << (S[i] ^ S[i - 1]);
    }
}
