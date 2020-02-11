#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 3e5 + 20;

int frq[maxN], frq2[maxN], n, _t;
vector<int> ans;
priority_queue<int, vector<int>, greater<int> > pq;
int main(){
    ericxiao;
    cin >> n;
    ans.resize(n + 1);
    for(int i = 0; i < n; i++){
        cin >> _t;
        frq[_t]++;
    }
    int hasOccMax = 0;
    for(int i = 1; i <= n; i++){
        frq2[frq[i]]++;
        if(frq[i] > hasOccMax) hasOccMax = frq[i];
    }



    sort(frq + 1, frq + 1 + n);
    reverse(frq + 1, frq + 1 + n);
    int t1, t2;
    for(int i = 1; i <= n; i++){
        pq = priority_queue<int, vector<int>, greater<int> >();
        for(int j = 1; j <= i; j++){
            pq.push(frq[j]);
        }
        for(int j = i + 1; j <= n; j++){
            t1 = pq.top();
            pq.pop();
            pq.push(t1 + frq[j]);
        }
        ans[i] = pq.top();
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << endl;

}
