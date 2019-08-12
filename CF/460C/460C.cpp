#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define S second
#define F first
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5;
int n, m, w, arr[maxN + 10];

bool can(int x){ //x is minheight
    int daysleft = m, currentAdd = 0;
    deque<pii> dq;
    for(int i = 0; i < n; i++){
        while(dq.size() && i - dq.front().F >= w){
            currentAdd -= dq.front().S;
            dq.pop_front();
        }
        if(arr[i] + currentAdd < x){
            if(daysleft < x - arr[i] - currentAdd){
                return false;
            } else {
                daysleft -= (x - arr[i] - currentAdd);
                dq.push_back({i, x - arr[i] - currentAdd});
                currentAdd += (x - arr[i] - currentAdd);
            }
        }
        //cout << "Currentadd(" << i << ") = " << currentAdd << endl;
    }
    return true;
}

signed main(){
    ericxiao;
    cin >> n >> m >> w;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int l = 0, r = 1e1, mm = (l + r) / 2;
    while(l + 1 < r){
        if(can(mm)){
            //cout << "Can(" << mm << ")" << endl;
            l = mm;
        } else {
            //cout << "Can't(" << mm << ")" << endl;
            r = mm;
        }
        mm = (l + r) / 2;

    }
    cout << l << endl;
}
