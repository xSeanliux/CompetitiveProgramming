#include <iostream>
#include <map>
#include <vector>
#include <utility>
#define int long long int
using namespace std;

int N, x, y, ans = 0;
vector<pair<int, int> > v;
map<int, int> freqs;

signed main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    int d2;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            d2 = (v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second);
            ans += freqs[d2];
            freqs[d2]++;
        }
    }
    cout << ans << endl;
}
