#include <iostream>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

const int INF = 1e7;

int N, M;
string s;
set<int> sts[25];
bool visited[25];

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> s;
        visited[i] = false;
        for(int j = 0; j < M; j++){
            if(s[j] == '1') sts[i].insert(j);
        }
    }
    int ans = M, minAt, minVal = 0;
    for(int r = 0; r < N; r++){
        minVal = INF;
        for(int i = 0; i < N; i++){
            if(minVal > sts[i].size() && !visited[i]){
                minAt = i;
                minVal = sts[i].size();
            }
        }
        ans -= minVal;
        visited[minAt] = true;
        //cout << "minat = " << minAt << ", minval = " << minVal << endl;
        vector<int> vals;
        vals.clear();
        for(int u : sts[minAt]) vals.push_back(u);
        for(int u : vals){
            //cout << "Looking at " << u << endl;
            for(int i = 0; i < N; i++){
                if(sts[i].count(u)){
                    //cout << "sts[" << i << "] has " << u << endl;
                    sts[i].erase(sts[i].find(u));
                }
            }
            //cout << "X" << endl;
        }
        cout << ans << endl;
    }
}
