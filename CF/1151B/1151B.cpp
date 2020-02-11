#include <iostream>
#include <vector>
#include <map>
#include <utility>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int n, m, x, arr[600][600];

map<int, vector<int> > mp, nmp;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        if(mp.count(arr[0][i])) continue;
        mp[arr[0][i]] = vector<int>();
        mp[arr[0][i]].push_back(i);
    }
    for(int i = 1; i < n - 1; i++){
        nmp = map<int, vector<int> >();
        for(int j = 0; j < m && nmp.size() <= m; j++){
            for(auto p : mp){
                if(nmp.count(p.F ^ arr[i][j])) continue;
                nmp[p.F ^ arr[i][j]] = p.S;
                nmp[p.F ^ arr[i][j]].push_back(j);
            }
        }
        mp = nmp;
    }
    if(n == 1){
        bool flg = 0;
        for(int j = 0; j < m; j++){
            if(arr[0][j]){
                cout << "TAK" << endl;
                cout << j + 1 << endl;
                return 0;
            }
        }
        cout << "NIE" << endl;
        return 0;
    }
    for(int i = 0; i < m; i++){
        for(auto p : mp){
            if(p.F != arr[n-1][i]){
                cout << "TAK" << endl;
                for(int k : p.S){
                    cout << k + 1 << " ";
                }
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    cout << "NIE" << endl;
}

