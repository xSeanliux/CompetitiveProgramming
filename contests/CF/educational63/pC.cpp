#include <iostream>
#include <vector>
#include <iostream>
#define int long long int
using namespace std;

int N, M;
vector<int> x, p;

int gcd(int a, int b){
    return (!b ? a : gcd(b, a % b));
}

signed main(){
    cin >> N >> M;
    x.resize(N); p.resize(M);
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    for(int i = 0; i < M; i++){
        cin >> p[i];
    }
    int cG = x[1] - x[0];
    for(int i = 2; i < N; i++){
        cG = gcd(cG, x[i] - x[i-1]);
    }
    for(int i = 0; i < M; i++){
        if(!(cG % p[i])){
            cout << "YES" << endl;
            cout << x[0] << " " << i + 1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

}
