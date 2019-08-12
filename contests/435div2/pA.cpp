#include <iostream>
#include <vector>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long int
using namespace std;

int N, x;
vector<int> vec;
vector<int> frq;
string s;

signed main(){
    cin >> N >> x;
    vec.resize(N);
    frq.resize(101);
    fill(frq.begin(), frq.end(), 0);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
        frq[vec[i]]++;
    }
    int ans = frq[x];
    frq[x] = 0;
    for(int i = 0; i < x; i++){
        if(!frq[i]) ans++;
    }
    cout << ans << endl;

}
