#include <iostream>
#define endl '\n'
#define int long long int
using namespace std;

int N;

int exp(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int res = exp(b, e/2);
    res = res * res % N;
    if(e % 2) res = res * b % N;
    return res;
}
signed main(){
    cin >> N;
    if(N == 1){
        cout << "YES" << endl;
        cout << 1 << endl;
        return 0;
    } else if(N == 4){
        cout << "YES" << endl;
        cout << "1 3 2 4" << endl;
        return 0;
    }
    bool isPrime = true;
    for(int i = 2; i*i <= N; i++){
        if(!(N % i)){
            isPrime = false;
            break;
        }
    }
    if(!isPrime){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << 1 << endl;
    for(int i = 2; i < N; i++){
        cout << (i * exp(i - 1, N - 2)) % N << endl;
    }
    cout << N << endl;
    return 0;
}
