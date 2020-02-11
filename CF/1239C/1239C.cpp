#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

deque<int> actual_queue;
vector<int> ans;
priority_queue<int, vector<int>, greater<int> > toque;
priority_queue<pii, vector<pii>, greater<pii> > events;

const int INF = 1e6;
int n, waittime, t;

signed main(){
    cin >> n >> waittime;
    ans.resize(n);
    for(int i = 0; i < n; i++){
        cin >> t;
        events.push({t, i});
    }
    int x;
    while(events.size()){
        pii ev = events.top(); //ev.F: time
        events.pop();
        //if ev.S = -1 means que pop
        //else means id with ev.S is going in
        //cout << "Time = " << ev.F << endl;
        if(ev.S == INF){
            ans[actual_queue.front()] = ev.F;
            //cout << "POP " << actual_queue.front() << endl;
            actual_queue.pop_front();
            if(actual_queue.size()){
                events.push({ev.F + waittime, INF});
            }
        } else {
            //cout << ev.S << " joins " << endl;
            toque.push(ev.S);
        }
        if(toque.size()){
            x = toque.top();
            toque.pop();
            if(!actual_queue.size()){
                //cout << "In queue: " << x << endl;
                actual_queue.push_back(x);
                events.push({ev.F + waittime, INF});
            } else if(actual_queue.back() > x){
                //cout << "In queue: " << x << endl;
                actual_queue.push_back(x);
            } else {
                toque.push(x);
            }
        }
    }
    for(int i : ans) cout << i << " ";
}
