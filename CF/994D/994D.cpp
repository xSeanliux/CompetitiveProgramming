#include <iostream>
#include <utility>
#include <vector>
#include <set>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 15;

int n, m, a, b;
vector<pii> A, B;
set<int> degA[maxN], degB[maxN], st;

int common(pii a, pii b){
    if((a.F == b.F && a.S != b.S) || (a.S != b.F && a.F == b.S)){
        return a.F;
    }
    if((a.S == b.F && a.F != b.S) || (a.S == b.S && a.F != b.F)){
        return a.S;
    }
    return -1;
}

int main(){
    cin >> n >> m;
    A.resize(n);
    B.resize(m);
    for(int i = 0; i < n; i++){
        cin >> A[i].F >> A[i].S;
    }
    for(int i = 0; i < m; i++){
        cin >> B[i].F >> B[i].S;
    }
    int com;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            com = common(A[i], B[j]);
            if(com != -1){
                //cout << "Adding " << com << " to a[" << i << "] and b[" << j << "]" << endl;
                degA[i].insert(com);
                degB[j].insert(com);
            }

        }
    }
    for(int i = 0; i < n; i++){
        if(degA[i].size() > 1){
            //cout << "degA[" << i << "]" << endl;
            cout << -1 << endl;
            return 0;
        }
        if(degA[i].size() == 1)
            st.insert(*degA[i].begin());
    }
    for(int i = 0; i < m; i++){
        if(degB[i].size() > 1){
            //cout << "degB[" << i << "]" << endl;
            cout << -1 << endl;
            return 0;
        }
        if(degB[i].size() == 1)
            st.insert(*degB[i].begin());
    }
    //cout << "ST: " << endl;
    //for(int u : st) cout << u << " ";
    //cout << endl;
    if(st.size() == 1){
        cout << *st.begin() << endl;
    } else{
        cout << 0 << endl;
    }
}
