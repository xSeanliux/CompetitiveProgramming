#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<int> > mp;

int N, M, x, a, b, ind = 1;

int main(){
    while(cin >> N >> M){
        mp.clear();
        ind = 1;
        while(N--){
            cin >> x;
            mp[x].push_back(ind++);
        }
        while(M--){
            cin >> b >> a;
            if(mp[a].size() < b){
                cout << 0 << endl;
            } else {
                cout << mp[a][b - 1] << endl;
            }
        }
    }
}

