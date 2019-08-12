#include <iostream>
#define int long long int
using namespace std;

int N;

signed main(){
    cin >> N;
    int ans = 0, m;
    for(int i = 1; i * i <= N; i++){
        if(!(N % i) && N/i - 1 > i){
            ans += N/i - 1;
        }
    }
    cout << ans << endl;
}


