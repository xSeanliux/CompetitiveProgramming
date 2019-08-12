#include <iostream>
#include <vector>
using namespace std;

const long long int MAXN = 1e7;
long long int T, n;
bool isPrime[MAXN];
vector<int> primes, factors;


int main(){
    cin >> T;
    while(T--){
        factors.clear();
        cin >> n;
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        for(int i = 9; i > 1; i--){
            while(!(n % i)){
                factors.push_back(i);
                n /= i;
            }
        }
        if(n > 1){
            cout << -1 << endl;
        } else {
            for(int i = factors.size() - 1; i >= 0; i--){
                cout << factors[i];
            }
            cout << endl;
        }
    }
}
