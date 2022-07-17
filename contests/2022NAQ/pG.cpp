#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e5 + 326;
bool isErr[maxN];

void insertNum(int x, vector<pii> &v) {
   if(!v.size()) {
       v.emplace_back(x, x);
       return;
   }
   pii p = v[v.size() - 1];
   if(p.S + 1 == x) v[v.size() - 1].S++;
   else v.emplace_back(x, x);
}

void output(vector<pii> &v) {
    for(int i = 0; i < v.size(); i++) {
        if(!i) cout << " ";
        else if(i == v.size() - 1) cout << " and ";
        else cout << ", ";
        if(v[i].F == v[i].S) cout << v[i].F;
        else cout << v[i].F << "-" << v[i].S;
    }
    cout << endl;
}

int main() {
    int C, N, x;
    cin >> C >> N;
    while(N--){
        cin >> x;
        isErr[x] = 1;
    }
    vector<pii> cor = vector<pii>(), err = vector<pii>();

    for(int i = 1; i <= C; i++) {
        if(isErr[i]) insertNum(i, err);
        else insertNum(i, cor);
    }

    cout << "Errors:";
    output(err);
    cout << "Correct:";
    output(cor);
}
