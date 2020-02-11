#include <iostream>
#include <stack>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5e6 + 10;

int N, vals[maxN], avg, ans = 0, take, t;

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> vals[i];
        avg += vals[i];
    }
    avg /= N;
    for(int i = 0; i < N; i++) vals[i] -= avg;
    stack<int> que;
    for(int i = 0; i < N; i++){
        if(vals[i] < 0) que.push(i);
        else {
            if(que.empty()) continue;
            t = que.top();
            take = min(vals[i], -vals[t]);
            vals[i] -= take;
            vals[t] += take;
            if(vals[i] == 0) que.pop();
            ans += (i - t) * take;
            for(int i = 0; i < N; i++) cout << vals[i] << " ";
            cout << endl;
        }
    }

}
