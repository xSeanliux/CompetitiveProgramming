#include <iostream>
#include <vector>
#include <string.h>
#include <numeric>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5;

string t, revs, revt;
vector<string> s;
vector<int> SA;
int N, mod[maxN + 10], begmatch[maxN + 10], endmatch[maxN + 10];

vector<int> getSA(string s){
    int l = s.length();
    s += "$";
    vector<pii> current, nex;
    vector<int> rk, newrk;
    current.resize(l + 1);
    nex.resize(l);
    rk.resize(l + 1);
    newrk.resize(l + 1);
    for(int i = 0; i <= l; i++){
        rk[i] = s[i];
    }
    for(int i = 0; i <= l; i++){
        current[i] = {i, i};
    }
    for(int i = 1; i <= l; i <<= 1){
        sort(current.begin(), current.end(), [=](pii a, pii b){
            return (rk[a.F] == rk[b.F]) ? rk[a.S] < rk[b.S] : rk[a.F] < rk[b.F];
        });

        newrk[ current[0].F ] = 0;
        for(int j = 1; j <= l; j++){
            newrk[ current[j].F ] = newrk[ current[j - 1].F ];
           // cout << "current[" << j <<"] = " << current[j].F << ", " << current[j].S << endl;
            //cout << "current[" << j - 1 <<"] = " << current[j - 1].F << ", " << current[j - 1].S << endl;
            if(!(rk[current[j].F] == rk[current[j - 1].F] && rk[current[j].S] == rk[current[j - 1].S]))
                newrk[ current[j].F ]++;
        }
        for(int j = 0; j <= l; j++){
            rk[j] = newrk[j];
        }
        /*
        cout << "Len: " << i << endl;
        for(auto p : current){
            cout << p.F << " " << p.S << " : " << s.substr(p.F, i) << " " << rk[p.F] << endl;
        }
        */
        for(int j = 0; j <= l; j++){
            current[j] = {j, min(j + i, l)};
        }
    }
    vector<int> res;
    res.resize(l);
    for(int i = 0; i <= l; i++){
        if(rk[i] == 0) continue;
        res[ rk[i] - 1 ] = i;
    }
    return res;
}


bool cmp1(int n, string s){
    string _s = t.substr(SA[n], s.length());
    return s > _s;
}

bool cmp2(string s, int n){
    string _s = t.substr(SA[n], s.length());
    return s < _s;
}

bool cmp3(int n, string s){
    string _s = revt.substr(SA[n], s.length());
    return s > _s;
}

bool cmp4(string s, int n){
    string _s = revt.substr(SA[n], s.length());
    return s < _s;
}

signed main(){
    ericxiao;
    cin >> t;
    SA = getSA(t);

    vector<int> ints;
    ints.resize(t.length() + 1);
    iota(ints.begin(), ints.end(), 0);
    fill(mod, mod + t.length() + 1, 0);
    cin >> N;
    s.resize(N);
    for(int i = 0; i < N; i++) cin >> s[i];
    int b, e;
    for(string str : s){
        b = (lower_bound(ints.begin(), ints.end(), str, cmp1) - ints.begin());
        e = (upper_bound(ints.begin(), ints.end(), str, cmp2) - ints.begin());
        mod[b]++;
        mod[e]--;
    }

    int currentpre = mod[0];
    for(int i = 0; i < t.length(); i++){
        if(i != 0) currentpre += mod[i];
        begmatch[ SA[i] ] = currentpre;
    }



    revt = t;
    reverse(revt.begin(), revt.end());
    SA = getSA(revt);
    fill(mod, mod + t.length() + 1, 0);


    for(string str : s){
        revs = str;
        reverse(revs.begin(), revs.end());
        b = (lower_bound(ints.begin(), ints.end(), revs, cmp3) - ints.begin());
        e = (upper_bound(ints.begin(), ints.end(), revs, cmp4) - ints.begin());
        //cout << "For " << revs << ", " << b << " - " << e << endl;
        mod[b]++;
        mod[e]--;
    }

    currentpre = mod[0];
    for(int i = 0; i < t.length(); i++){
        if(i != 0) currentpre += mod[i];
        endmatch[ t.length() - 1 - SA[i] ] = currentpre;
    }



    int ans = 0;
    for(int i = 0; i < t.length() - 1; i++){
        ans += endmatch[i] * begmatch[i + 1];
    }
    cout << ans << endl;

}
