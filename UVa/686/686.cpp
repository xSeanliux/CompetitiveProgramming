#include <iostream>
#include <vector>
#include <map>
#define MAX (1 << 14)
using namespace std;

bool isPrime[MAX + 5];
vector <int> primes;
map <int, int> ans;

void init(){
    for(int i = 0; i < MAX; i++){
        isPrime[i] = i % 2;
    }
    isPrime[1] = false;
    isPrime[2] = true;
    for(int i = 2; i <= MAX; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
        for(int j = 0; j < primes.size() && primes[j] * i <= MAX; j++){
            isPrime[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
    }
}

int query;

int main(){
    init();
    for(int i = 0; i < primes.size(); i++){
        //printf("Checking: %d\n", primes[i]);
        for(int j = 0; j <= i; j++){
            if(!ans.count(primes[i] + primes[j])){
                ans.insert(pair<int, int>(primes[i] + primes[j], 1));
                //printf("%d++\n", primes[i] + primes[j]);
            } else {
                ans[(primes[i] + primes[j])]++;
                //printf("%d++\n", primes[i] + primes[j]);
            }
        }
    }
    while(scanf("%d", &query) != EOF){
        if(!query) return 0;
        else if(ans.count(query)){
            printf("%d\n", ans[query]);
        } else {
            printf("0\n");
        }
    }
}
