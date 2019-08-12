#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

int T, n, m;
char mp[2000][2000];
map<char, vector<pii> > poss;

int main(){
    ericxiao;
    cin >> T;
    while(T--){
        poss = map<char, vector<pii> >();
        char maxLetter = -1;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mp[i][j];
                if(mp[i][j] != '.'){
                    poss[mp[i][j]].push_back({i, j});
                    maxLetter = max(maxLetter, mp[i][j]);
                }
            }
        }
        if(!poss.size()){
            cout << "YES" << endl <<  0 << endl;
            continue;
        }
        char testmp[n][m];
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) testmp[i][j] = '.';
        bool canDo = true;
        for(char c = 'a'; c <= maxLetter; c++){
            if(!poss.count(c)){ //place it in maxLetter - basically means do nothing
                continue;
            }
            sort(poss[c].begin(), poss[c].end());
            if(poss[c].size() > 1){
                bool isVer = false, isHor = false;
                for(auto p : poss[c]){
                    if(p.first != poss[c][0].first) isHor = true;
                    if(p.second != poss[c][0].second) isVer = true;
                }
                if(!(isHor ^ isVer)){
                    canDo = false;
                    break;
                }
                for(int i = poss[c].begin()->first; i <= poss[c].rbegin()->first; i++){
                    testmp[i][poss[c][0].second] = c;
                }
                for(int i = poss[c].begin()->second; i <= poss[c].rbegin()->second; i++){
                    testmp[poss[c][0].first][i] = c;
                }
            } else {
                testmp[poss[c][0].first][poss[c][0].second] = c;
            }
        }

        if(!canDo){
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < n && canDo; i++){
            for(int j = 0; j < m && canDo; j++){
                if(testmp[i][j] != mp[i][j]){
                    canDo = false;
                    break;
                }
            }
        }
        if(!canDo){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << maxLetter - 'a' + 1 << endl;
        for(char c = 'a'; c <= maxLetter; c++){
            if(!poss.count(c)){
                cout << poss.rbegin()->second[0].first + 1 << " " << poss.rbegin()->second[0].second + 1 << " "  << poss.rbegin()->second[0].first + 1 << " " << poss.rbegin()->second[0].second + 1 << endl;
            } else {
                cout << poss[c].begin()->first + 1 << " " << poss[c].begin()->second + 1 << " " << poss[c].rbegin()->first + 1 << " " << poss[c].rbegin()->second + 1 << endl;
            }
        }
    }
}
