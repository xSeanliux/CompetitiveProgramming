#include <iostream>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 326, INF = 2e9;

int N, dp[maxN], from[maxN], col[maxN];
pii arr[maxN];

int main() {
    cin >> N;
    arr[0] = {0, 0};
    for(int i = 1; i <= N; i++){
        cin >> arr[i].F;
        arr[i].S = i;
    }
    sort(arr, arr + N + 1);
    dp[1] = arr[1].F;
    dp[0] = 0;
    for(int i = 1; i <= 5; i++) {
       dp[i] = arr[i].F - arr[1].F;
       from[i] = 0;
    }
    dp[1] = dp[2] = INF;
    int curBest = 0;
    for(int i = 3; i <= N; i++) {
        dp[i] = dp[curBest] - arr[curBest + 1].F + arr[i].F;
        from[i] = curBest;
        if(dp[curBest] - arr[curBest + 1].F > dp[i - 2] - arr[i - 1].F) curBest = i - 2;
    }
    /*
    for(int i = 6; i <= N; i++) {
        dp[i] = INF;
        from[i] = 0;
        for(int j = i - 6; j <= i - 3; j++) {
            if(dp[j] - arr[j + 1].F + arr[i].F < dp[i]){
                dp[i] = dp[j] - arr[j + 1].F + arr[i].F;
                from[i] = j;
            }
        }
    }
    */
    int cur = N, curcol = 1;
    while(cur) {
        for(int i = from[cur] + 1; i <= cur; i++) col[arr[i].S] = curcol;
        cur = from[cur];
        curcol++;
    }
    cout << dp[N] << " " << curcol - 1 << endl;
    for(int i = 1; i <= N; i++) cout << col[i] << " \n"[i == N];
}
