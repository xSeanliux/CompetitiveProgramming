#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


int N, K, x;
bool canDo = true;
vector<int> deg;
vector<vector<int> > v; //sort by dist
vector<pair<int, int> > d, allEdges;
int main(){
    cin >> N >> K;
    d.clear();
    d.resize(N);
    deg.clear();
    deg.resize(N);
    fill(deg.begin(), deg.end(), 0);
    v.clear();
    v.resize(N);
    allEdges.clear();
    for(int i = 0; i < N; i++){
        cin >> x;
        d[i] = {i, x};
        v[x].push_back(i);
    }
    sort(d.begin(), d.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });
    if(v[0].size() != 1){
        cout << -1 << endl;
        return 0;
    }
    for(auto p : d){//p.first: index; p.second: dist
        if(!p.second) continue;
        if(v[p.second - 1].size() == 0){ //crucial otherwise won't go into loop
            cout << -1 << endl;
            return 0;
        }
        for(int i : v[p.second - 1]){
            if(deg[i] < K){
                deg[i]++;
                deg[p.first]++;
                allEdges.push_back({i, p.first});
                break;
            } else if(i == v[p.second - 1][v[p.second - 1].size() - 1]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << allEdges.size() << endl;
    for(auto p : allEdges){
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}
