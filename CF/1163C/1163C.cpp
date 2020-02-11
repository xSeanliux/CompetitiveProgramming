#include <iostream>
#include <string.h>
#include <algorithm>
#include <set>
#include <utility>
#include <map>
#include <vector>
#define pss pair<string,string>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

set<pss> st;
map<string, int> mp;
vector<pii> points;

int N, x, y;

int gcd(int a, int b){
    return (!b ? a : gcd(b, a % b));
}

int Abs(int x){
    return (x > 0 ? x : -x);
}

string Div(int a, int b){
    if(!b) return "INF";
    if(!a) return "0";
    int sgn = (a * b > 0);
    a = Abs(a);
    b = Abs(b);
    int g = gcd(a, b);
    a /= g;
    b /= g;
    string res = (sgn ? "" : "-") + to_string(a) + "/" + to_string(b);
    return res;
}

pss getLine(pii p1, pii p2){
    string m, k;
    if(p1.F == p2.F){
        m = "INF";
        k = to_string(p2.F);
    } else {
        m = Div(p1.S - p2.S, p1.F - p2.F);
        k = Div(p2.S*p1.F - p1.S*p2.F, p1.F - p2.F);
    }
    return {m, k};
}

signed main(){
    cin >> N;
    points.resize(N);
    pss L;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        points[i] = {x, y};
        for(int j = 0; j < i; j++){
            L = getLine(points[i], points[j]);
            st.insert(L);
        }
    }
    int ans = st.size() * (st.size() - 1) / 2;
    for(pss p : st){
        mp[p.F]++;
    }
    for(auto p : mp){
        ans -= p.S * (p.S - 1) / 2;
    }
    cout << ans << endl;
}



