#include <iostream>
#include <utility>
using namespace std;

const int MAXN = 1e5, INF = 1 << 30;
pair<int, int> arr[MAXN + 10];

int N, K, l, r;

int main(){
    arr[0] = {-INF, 1};
    while(cin >> N >> K){
        if(!N && !K) return 0;
        for(int i = 1; i <= N; i++) arr[i] = {i - 1, i + 1};
        arr[N + 1] = {N, INF};
        while(K--){
            cin >> l >> r;
            int rE = arr[r].second, lE = arr[l].first;
            if(lE == 0) cout << "*";
            else cout << lE;
            cout << " ";
            if(rE == N + 1) cout << "*";
            else cout << rE;
            arr[lE].second = rE;
            arr[rE].first = lE;
            cout << endl;
        }
        cout << "-" << endl;
    }
}
