#include <iostream>
#include <math.h>

using namespace std;
long long int _t, N, c;
int MAX = 1000000000;
int get(int N){
    for(long long int i = 1; i < MAX; i++){
        long long int k = i * (i + 1) / 2;
        if(k >= N && (k % 2 == N % 2)){
            return i;
        }
    }
}

int main(){
    cin >> c;
    for(int ia = 0; ia < c; ia++){
        if(ia > 0){
            cout << endl;
        }
        cin >> N;
        int ans = get(abs(N));
        cout << ans << endl;
    }
}
