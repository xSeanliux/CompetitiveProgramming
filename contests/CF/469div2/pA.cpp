#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#define int long long int
using namespace std;

int N, K;
map<int, int> freqs;
vector<pair<int ,int> > ps;
int ans = 0;
signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> K;
        freqs[K]++;
    }
    for(auto i : freqs) ps.push_back(i);
    ans = ps.size();
    if(ps[0].first == 0) ans--;
    cout << ans << endl;
}
