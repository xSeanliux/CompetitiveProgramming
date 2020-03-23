#include <iostream>
#include <deque>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e5 + 10;

int N, arr[maxN], dp[maxN];

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        deque<int> dq;
        dq.push_back(arr[i]);
        dp[i] = 1 + dp[i - 1];
        for(int j = i - 1; j; j--){
            dq.push_front(arr[j]);
            int a;
            while(dq.size() > 1 && dq[0] == dq[1]){
                a = dq.front();
                dq.pop_front();
                dq.pop_front();
                dq.push_front(a + 1);
            }
            dp[i] = min(dp[i], dp[j - 1] + (int)dq.size());
        }
        //cout << "dp[" << i << "]" << "  = " << dp[i] << endl;
    }
    cout << dp[N] << endl;
}
