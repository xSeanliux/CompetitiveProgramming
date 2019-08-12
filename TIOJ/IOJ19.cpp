#include <iostream>
#include <map>
using namespace std;

int N, a, x, ans = 0;
map<int, int> cnt;

int main(){
    cnt.clear();
    cin >> N >> x;
    for(int i = 0; i < N; i++){
        cin >> a;
        if(cnt.count(a ^ x)){
            ans += cnt[a ^ x];
        }
        if(cnt.count(a)) cnt[a]++;
        else cnt.insert({a, 1});
    }
    cout << ans << endl;
}
