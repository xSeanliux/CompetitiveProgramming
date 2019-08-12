#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const double eps = 1e-10;
int N, ans = 0;
vector<double> v;

int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                ans += (fabs(v[i] + v[j] - v[k]) < eps);
            }
        }
    }
    cout << ans << endl;
}
