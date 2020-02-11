#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 5010, maxC = 31700;
bool isPrime[maxC];
vector<int> primes;
set<int> isBad;

void init(){
    fill(isPrime, isPrime + maxC, true);
    isPrime[1] = false;
    for(int i = 2; i < maxC; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int p : primes){
            if(i * p >= maxC) break;
            isPrime[i * p] = false;
            if(!(i % p)) break;
        }
    }
}

int score(int x){
    int r = 0, flg;
    for(int p : primes){
        if(p * p > x) break;
        if(!(x % p)){
            flg = (isBad.count(p) ? -1 : 1);
            while(!(x % p)){
                x /= p;
                r += flg;
            }
        }
    }
    if(x > 1) r += (isBad.count(x) ? -1 : 1);
    return r;
}

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

int N, M, p, x, ans, currentChange;
int arr[maxN], scores[maxN], ds[maxN], gpre[maxN]; //delta score

int main(){
    init();
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        gpre[i] = gcd(gpre[i - 1], arr[i]);
    }
    for(int i = 0; i < M; i++){
        cin >> p;
        isBad.insert(p);
    }
    for(int i = 1; i <= N; i++){
        ds[i] = (gpre[i] == gpre[i - 1] ? ds[i - 1] : -score(gpre[i]));
        scores[i] = score(arr[i]);
        ans += scores[i];
    }
    /*
    for(int i = 1; i <= N; i++){
        cout << scores[i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= N; i++){
        cout << ds[i] << " ";
    }
    cout << endl;
    */
    for(int i = N; i; i--){
        if(ds[i] - currentChange > 0){
            ans += (ds[i] - currentChange) * i;
            currentChange = ds[i];
        }
    }
    cout << ans << endl;
}
