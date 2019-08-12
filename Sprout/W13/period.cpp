#include <iostream>
#include <stack>
#include <utility>
#define int long long int
using namespace std;

string s;
const int maxN = 1e6;
int N, z[maxN + 10];
deque<pair<int, int> > dq;


signed main(){
    cin >> N >> s;
    int n = N;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }

    int ans = 0; //get
    stack<pair<int, int> > stk;
    pair<int, int> p = {0, 0};
    for(int i = 1; i < n; i++){
        if(z[i]){
            p = {i, i + z[i]};
            stk.push(p);
        }
        while(!stk.empty() && stk.top().second <= i){
            stk.pop();
        }
        if(stk.empty()){
            ans += 0;
        } else {
            ans += stk.top().first;
        }
    }
    cout << ans << endl;

}
