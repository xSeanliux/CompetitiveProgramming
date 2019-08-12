#include <iostream>
#include <map>
#include <math.h>
#include <string.h>
#define int long long int
using namespace std;

map<string, int> mp;

string getRep(int x){
    string s = "";
    for(int i = 0; (1LL << i) <= x; i++){
        s = (char)(((x & (1LL << i)) > 0) + '0') + s;
    }
    return s;
}

void addRoute(int u, int v, int w){
    string rU = getRep(u), rV = getRep(v);
    if(rU.length() > rV.length()) swap(rV, rU);
    string A = "";
    for(int i = 0; i < rU.length(); i++){
        if(rU[i] == rV[i]){
            A += rU[i];
        } else {
            break;
        }
    }
    //cout << rU << " " << rV << endl;
    //cout << "A = " << A << endl;
    rU = rU.substr(A.length(), rU.length());
    rV = rV.substr(A.length(), rV.length());
    string X = A;
    //cout << rU << " " << rV << endl;
    for(int i = 0; i < rU.length(); i++){
        X = X + rU[i];
        mp[X] += w;
    }
    X = A;
    for(int i = 0; i < rV.length(); i++){
        X = X + rV[i];
        mp[X] += w;
    }
}

int getAns(int u, int v){
    string rU = getRep(u), rV = getRep(v);
    if(rU.length() > rV.length()) swap(rV, rU);
    string A = "";
    for(int i = 0; i < rU.length(); i++){
        if(rU[i] == rV[i]){
            A += rU[i];
        } else {
            break;
        }
    }
    rU = rU.substr(A.length(), rU.length());
    rV = rV.substr(A.length(), rV.length());
    string X = A;
    //cout << rU << " " << rV << endl;
    int cost = 0;
    for(int i = 0; i < rU.length(); i++){
        X = X + rU[i];
        if(mp.count(X))
            cost += mp[X];
    }
    X = A;
    for(int i = 0; i < rV.length(); i++){
        X = X + rV[i];
        if(mp.count(X))
            cost += mp[X];
    }
    return cost;
}


int q, c, u, v, w;

signed main(){
    cin >> q;
    while(q--){
        cin >> c;
        if(c == 1){
            cin >> u >> v >> w;
            addRoute(u, v, w);
        } else {
            cin >> u >> v;
            cout << getAns(u, v) << endl;
        }
    }
}
