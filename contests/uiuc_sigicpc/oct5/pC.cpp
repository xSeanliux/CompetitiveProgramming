#include <iostream>
#define int long long int
using namespace std;

int N, K;

signed main(){
    cin >> N >> K;
    if(K <= 1) cout << 1 << endl;
    else if(K == 2) cout << 1 + ((N) * (N - 1) / 2) << endl;
    else if(K == 3) cout << 1 +  ((N) * (N - 1) / 2) + (N * (N - 1) * (N - 2) / 6 * 2) << endl;
    else cout << 1 + ((N) * (N - 1) / 2) + (N * (N - 1) * (N - 2) / 6 * 2) + N * (N - 1) * (N - 2) * (N - 3) / 24 * 9 << endl;
}
