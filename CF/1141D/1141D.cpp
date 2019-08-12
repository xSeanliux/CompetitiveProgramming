#include <iostream>
#include <map>
#include <deque>
#include <utility>
#include <vector>
#define pii pair<int,int>
#include <string.h>
using namespace std;

map<char, deque<int> > lmp, rmp;
vector<pii> ans;
int N;
string l, r;

int main(){
    cin >> N >> l >> r;
    for(int i = 0; i < N; i++){
        lmp[l[i]].push_back(i + 1);
        rmp[r[i]].push_back(i + 1);
    }
    for(auto p : lmp){
        //cout << p.first << " " << endl;
        if(p.first == ('?')) continue;
        while(p.second.size() && rmp[p.first].size()){
            ans.push_back({p.second.front(), rmp[p.first].front()});
            p.second.pop_front();
            rmp[p.first].pop_front();
        }
        while(p.second.size() && rmp['?'].size()){
            ans.push_back({p.second.front(), rmp['?'].front()});
            p.second.pop_front();
            rmp['?'].pop_front();
        }
    }
    for(auto p : rmp){
        while(p.second.size() && lmp['?'].size()){
            ans.push_back({lmp['?'].front(), p.second.front()});
            p.second.pop_front();
            lmp['?'].pop_front();
        }
    }
    cout << ans.size() << endl;
    for(pii p : ans){
        cout << p.first << " " << p.second << endl;
    }
}
