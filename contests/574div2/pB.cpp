#include <iostream>
#include <math.h>
#define int long long int
using namespace std;

int n, k;

int SQRT(int t){
    int m = floor(sqrt(t));
    for(int i = m - 2; i <= m + 2; i++){
        if(i * i == t) return i;
    }
}

signed main(){
    cin >> n >> k;
    int T = (SQRT(9 + 8*(n + k)) - 3) / 2;
    cout << n - T << endl;
}
