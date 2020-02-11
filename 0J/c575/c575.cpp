#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 1e5, INF = 1e15;

vector<int> places;
int N, K, x;

bool can(int x){
    //cout << "Range = " << x << endl;
    int cnt = 0, last = -INF;
    for(int i = 0; i < N; i++){
        if(last + x < places[i]){
            cnt++;
            last = places[i];
            //cout << "last = " << places[i] << endl;
        }
    }
    return (cnt <= K);
}

signed main(){
    ericxiao;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> x;
        places.push_back(x);
    }
    sort(places.begin(), places.end());
    int l = 1, r = INF, m;
    while(l + 1 < r){
        m = (l + r) / 2;
        if(can(m)) r = m;
        else l = m;
    }
    cout << r << endl;
}
