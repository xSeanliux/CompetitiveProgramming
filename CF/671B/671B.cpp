#include <iostream>
#include <math.h>
#include <utility>
#include <map>
#include <vector>
using namespace std;

map<int, int> freqs;
int N, K, x;

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> x;
        freqs[x]++;
    }
    vector<pair<int, int> > v;
    for(auto i : freqs){
        v.push_back(i);
    }
    int poor = 0, rich = freqs.size() - 1;
    while(poor + 1 < rich){
        if(K <= 0) break;
        //coins needed for poor to advance to next: v[poor].second * (v[poor + 1].first - v[poor].first)
        if(v[poor].second * (v[poor + 1].first - v[poor].first) < v[rich].second * (v[rich].first - v[rich - 1].first)){
            //move v[poor].second * (v[poor + 1].first - v[poor].first) steps
            if(v[poor].second * (v[poor + 1].first - v[poor].first) > K){
                cout << v[rich].first - v[poor].first << endl;
                return 0;
            } else {
                K -= v[poor].second * (v[poor + 1].first - v[poor].first);
                v[rich].
            }
        }
    }
}
