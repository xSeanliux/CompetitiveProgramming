#include <iostream>
#include <stack>
#define lld long long int
using namespace std;

stack<pair<long long int, long long int> > stk;
long long int N, x, mA = 0;

int main(){
    stk.push({0, 0});
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> x;
        while(stk.top().first > x){
            auto p = stk.top();
            stk.pop();
            mA = max(mA, (i - stk.top().second - 1) * p.first);
        }
        stk.push({x, i});
    }
    while(stk.size() > 1){
        auto p = stk.top();
        stk.pop();
        mA = max(mA, (N - stk.top().second) * p.first); //no -1 because include rightmost block.
    }
    printf("%lld\n", mA);
}
