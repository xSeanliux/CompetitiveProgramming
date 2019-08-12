#include <iostream>
#include <map>
using namespace std;

map<int, int> pos, neg;

int n, x;

int main(){
    cin >> n;
    pos.clear();
    neg.clear();
    int ans = 0, cnt = 1;
    while(n--){
        cin >> x;
        if(pos.count(cnt + x)) {
            ans += pos[cnt + x];
            pos[cnt + x]++;
        } else {
            pos.insert({cnt + x, 1});
        }
        if(neg.count(cnt - x)) {
                ans += neg[cnt - x];
                neg[cnt - x]++;
        } else {
            neg.insert({cnt - x, 1});
        }
    }
    cout << ans << endl;
}
