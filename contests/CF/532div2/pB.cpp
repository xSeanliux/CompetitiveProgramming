#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, K, t; //needs

int main(){
    cin >> N >> K;
    map<int, int> mp;
    vector<int> todel;
    for(int i = 0; i < K; i++){
        cin >> t;
        if(mp.count(t)){
            mp[t]++;
        } else {
            mp.insert(pair<int, int>(t, 1));
        }
        if(mp.size() >= N){
            cout << 1;
            todel.clear();
            for(auto p : mp){
                p.second--;
                if(!p.second) todel.push_back(p.first);
            }
            for(auto i : todel){
                mp.erase(mp.find(i));
            }
        } else {
            cout << 0;
        }
    }
}
