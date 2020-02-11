#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

const int maxN = 2e5 + 10;

int T, N, vals[maxN];

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < 2 * N; i++){
            cin >> vals[i];
        }
        sort(vals, vals + 2 * N);
        cout << vals[N] - vals[N - 1] << endl;
    }
}
