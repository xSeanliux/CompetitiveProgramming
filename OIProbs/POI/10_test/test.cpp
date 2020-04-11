#include <iostream>
#include <algorithm>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
vector<int> pos[maxN];
int N, M, Q, x;

int main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        pos[x].push_back(i);
    }
    cin >> Q;
    while(Q--){
        cin >> M;
        int cpos = -1;
        bool f = true;
        for(int i = 0; i < M; i++){
            cin >> x;
            //cout  << "x = " << x << endl;
            auto it = upper_bound(pos[x].begin(), pos[x].end(), cpos);
            if(it == pos[x].end()){
                f = false;
                //break;
            } else {
                cpos = *it;
            }


            //cout << "cpos = " << cpos << endl;
        }
        cout << (f ? "TAK" : "NIE") << endl;
    }
}
