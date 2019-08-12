#include <iostream>
#include <utility>
#include <stack>
using namespace std;

long long int T, n, x, ans = 0;

int main(){
    cin >> T;
    while(T--){
        stack<pair<long long int, long long int> > stk;
        ans = 0;
        cin >> n;
        stk.push({1LL << 32 + 10, 0}); //base case
        for(int i = 0; i < n; i++){
            scanf("%lld", &x);
            while(stk.top().first < x){
                //cout << "Popping " << stk.top().first << endl;
                ans += stk.top().second;
                stk.pop();
            }
            if(stk.top().first == x){
                pair<long long int, long long int> _p = stk.top();
                stk.pop();
                ans += _p.second;
                ans += min(stk.top().second, 1LL);
                //printf("Adding : %d: %d, %d: %d\n", _p.first, _p.second, stk.top().first, stk.top().second);
                stk.push(_p);
                stk.top().second++;
            } else {
                ans += min(stk.top().second, 1LL);
                stk.push({x, 1});
            }
        }
        printf("%lld\n", ans);
    }
}
