#include <iostream>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

int N, a, b;
vector<pii> vec, cl, co, tmp;

inline int Abs(int x){
    return (x > 0 ? x : -x);
}

inline int dist(pii a, pii b){
    return Abs(a.F - b.F) + Abs(a.S - b.S);
}

inline int lvl(pii a){
    return max(a.F, a.S);
}

signed main(){
    ericxiao;
    cin >> N;
    vec.resize(N);
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        vec[i] = {a, b};
    }
    sort(vec.begin(), vec.end(), [](pii a, pii b){
         return lvl(a) < lvl(b);
    });

    cl.push_back({0, 0});
    co.push_back({0, 0});
    int k = 0;
    for(int i = 0; i < N; i++){
        tmp.clear();
        int t = 0;
        k++;
        while(t + i < N && lvl(vec[t + i]) == lvl(vec[i])){
            tmp.push_back(vec[t + i]);
            t++;
        }
        sort(tmp.begin(), tmp.end(), [](pii a, pii b){
            return (a.F == b.F ? a.S > b.S : a.F < b.F);
        });
        for(int j = 0; j < tmp.size(); j++){
            (k % 2 ? cl : co).push_back(tmp[j]);
            (k % 2 ? co : cl).push_back(tmp[tmp.size() - j - 1]);
        }
        i += t - 1;
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= N; i++){
        ans1 += dist(cl[i], cl[i - 1]);
        cout << cl[i].F << ", " << cl[i].S << endl;
    }
    for(int i = 1; i <= N; i++){
        ans2 += dist(co[i], co[i - 1]);
    }
    cout << min(ans1, ans2) << endl;
}
