#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N;

vector<int> vec, pre;
map<int, vector<pii> > mp;
vector<pii> res;
inline int sum(int l, int r){
    return pre[r] - (l > 0 ? pre[l - 1] : 0);
}

vector<pii> run(vector<pii> arr){
    int currentR = -10;
    vector<pii> res;
    for(auto p : arr){
        if(p.F > currentR){
            res.push_back(p);
            currentR = p.S;
        }
    }
    return res;
}

signed main(){
    ericxiao;
    cin >> N;
    vec.resize(N);
    pre.resize(N);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
        pre[i] = vec[i];
        if(i) pre[i] += pre[i - 1];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            mp[sum(j, i)].push_back({j, i});
        }
    }
    int maxlen = 0;
    for(auto &p : mp){
        sort(p.S.begin(), p.S.end(), [=](const pii a, const pii b){
            return a.S < b.S;
        });
        maxlen = max(maxlen, (int)run(p.S).size());
    }
    cout << maxlen << endl;
    for(auto p : mp){
        res = run(p.S);
        if(res.size() == maxlen){
            for(auto t : res){
                cout << t.F + 1 << " " << t.S + 1 << endl;
            }
            return 0;
        }
    }
}
