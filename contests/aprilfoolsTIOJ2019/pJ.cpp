#include <iostream>
#define lld long long int
using namespace std;

const int N = 3185327;
int a, b;

int main(){
    for(int i = 0 ; i < N; i++) cin >> a;
    unsigned long long int ans = 0;
    for(int i = 0; i < N; i++){
        cin >> a;
        ans += a * a;
    }
    cout << ans << endl;
}
