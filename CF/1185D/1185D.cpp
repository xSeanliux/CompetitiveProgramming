#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<pii> vec, d1, d2, dO;
int N, t;

int main(){
    ericxiao;
    cin >> N;
    if(N <= 3){
        cout << "1" << endl;
        return 0;
    }
    vec.resize(N);
    for(int i = 0; i < N; i++){
        cin >> t;
        vec[i] = {t, i + 1};
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < N; i++){
        if(i != 0) d1.push_back(vec[i]);
        if(i != 1) d2.push_back(vec[i]);
        dO.push_back(vec[i]);
    }
    //check delete one
    int d = d1[1].first - d1[0].first;
    for(int i = 1; i < N - 1; i++){
        if(d1[i].first - d1[i - 1].first != d){
            break;
        } else if (i == N - 2) {
            cout << dO[0].second << endl;
            return 0;
        }
    }
    d = d2[1].first - d2[0].first;
    for(int i = 1; i < N - 1; i++){
        if(d2[i].first - d2[i - 1].first != d){
            break;
        } else if (i == N - 2) {
            cout << dO[1].second << endl;
            return 0;
        }
    }
    int nedDel = -1; //index of the thingy that needs to be deleted
    d = dO[1].first - dO[0].first;
    for(int i = 0; i < N - 1; i++){
        if(dO[i].second == nedDel) continue;
        if(dO[i + 1].first - dO[i].first != d){
            //cout << "I:" << i << endl;
            if(nedDel == -1 && i == N - 2){
                nedDel = dO[i + 1].second;
                continue;
            }
            if(nedDel != -1 || dO[i + 2].first - dO[i].first != d){
                cout << -1 <<  endl;
                return 0;
            } else {
                nedDel = dO[i + 1].second;
                //cout << "SETTING" << endl;
            }
        }
    }
    if(nedDel == -1 && d > 0) cout << -1 << endl;
    else if(nedDel == -1 && !d) cout << 1 << endl;
    else cout << nedDel << endl;
}

