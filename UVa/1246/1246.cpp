#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10000;

bool isPrime[ N + 5 ];
vector<int> primes, allow, ans;
int factors[ N + 5 ], C;

void getPrime(){
    for(int i = 0; i <= N; i++) isPrime[i] = i % 2;
    isPrime[1] = false;
    isPrime[2] = true;
    for(int i = 3; i <= N; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int j = 0; j < primes.size() && primes[j] * i <= N; j++){
            isPrime[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
    }
}

int L, H;

int main(){
    getPrime();
    for(int i = 1; i <= N; i++) factors[i] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j * j <= i; j++){
            if(!(i % j)){
                factors[i] += 2;
                if(j * j == i) factors[i]--;
            }
        }
        //cout << "factors[" << i << "] = " << factors[i] << endl;
    }
    allow.clear();
    for(int i = 2; i <= N; i++){
        if(isPrime[factors[i]]) allow.push_back(i);
    }
    cin >> C;
    while(C--){
        scanf("%d %d", &L, &H);
        ans.clear();
        int lInd = lower_bound(allow.begin(), allow.end(), L) - allow.begin(), uInd = upper_bound(allow.begin(), allow.end(), H) - allow.begin() - 1;
        for(int i = lInd; i <= uInd; i++){
            ans.push_back(allow[i]);
        }
        if(!ans.size()){
            printf("-1\n");
        } else {
            for(int i = 0; i < ans.size(); i++){
                if(i) printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
}
