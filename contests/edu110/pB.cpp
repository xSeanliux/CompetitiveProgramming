#include <iostream>
#include <vector>
using namespace std;

inline int gcd(int a, int b){
    return !b ? a : gcd(b ,a % b);
}
inline void solve(){
    int N;
    cin >> N;
    vector<int> ev = vector<int>(), od = vector<int>(), vec = vector<int>();
    int x;
    for(int i = 0; i < N; i++){
        cin >> x;
        (x & 1 ? od : ev).push_back(x);
    }
    for(int x : ev) vec.push_back(x);
    for(int y : od) vec.push_back(y);
    int cnt = 0;
    for(int i = 0; i < N; i++) for(int j = i + 1; j < N; j++){
        cnt += (gcd(vec[i], vec[j] * 2) > 1);
    }
    cout << cnt << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
