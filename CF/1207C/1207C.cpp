#include <iostream>
#include <numeric>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

vector<int> a, b, c;
set<int> st;

int main(){
    a.resize(100);
    iota(a.begin(), a.end(), 0);
    for(int i = 0; i < 100; i++){
        for(int j = i + 1; j < 100; j++){
            c.push_back(a[i] ^ a[j]);
        }
    }
    for(int i = 101; i < (1 << 14); i++){
        if(!st.count(i)){
            b.push_back(i);
            for(int u : c){
                st.insert(i ^ u);
            }
        }
        if(b.size() == 100) break;
    }
    int a1, a2;
    cout << "?";
    for(int u : b) cout << " " << u;
    cout << endl;
    cout << flush;
    cin >> a1;
    cout << "?";
    for(int u : a) cout << " " << u;
    cout << endl;
    cout << flush;
    cin >> a2;
    int k = a1 ^ a2;
    for(int i : b){
        for(int j : a){
            if((i ^ j) == k){
                cout << "! " << (i ^ a1) << endl;
                cout << flush;
                return 0;
            }
        }
    }

}
