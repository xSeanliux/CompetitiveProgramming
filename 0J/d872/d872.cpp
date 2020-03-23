#include <iostream>
#include <algorithm>
#include <deque>
#define ericxiao ios_base::sync_with_stdio(0);
#define endl '\n'
using namespace std;

int N, x;
deque<int> dq;

int main(){
    ericxiao;
    while(cin >> N){
        if(!N){
            cout << 0 << endl;
            continue;
        }
        dq = deque<int>();
        while(N--){
            cin >> x;
            dq.push_back(x);
        }
        sort(dq.begin(), dq.end());
        int a, b, c, d, ans = 0;
        while(dq.size() >= 4){
            a = dq.front();
            dq.pop_front();
            b = dq.front();
            dq.pop_front();
            d = dq.back();
            dq.pop_back();
            c = dq.back();
            dq.pop_back();
            ans += min(b + d + a + b, c + d + 2 * a);
            dq.push_front(b);
            dq.push_front(a);
        }
        if(dq.size() <= 2){
            ans += dq.back();
        } else {
            ans += dq[2] + dq[1] + dq[0];
        }
        cout << ans << endl;
    }
}
