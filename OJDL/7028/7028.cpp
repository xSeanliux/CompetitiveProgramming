#include <iostream>
#include <vector>
#define MAX 1000009
using namespace std;

bool isPrime[MAX];
vector <int> primes;

void getPrime(){
    for(int i = 0; i < MAX; i++)
        isPrime[i] = i % 2;
    isPrime[1] = false;
    isPrime[2] = true;
    primes.push_back(2);
    for(int i = 3; i < MAX; i += 2){
        if(isPrime[i])
            primes.push_back(i);
        for(int j = 0; j < primes.size() && primes[j] * i < MAX; j++){
            isPrime[i * primes[j]] = false;
            if(!(i % primes[j])) break;
        }
    }
}

int N, K;

int main(){
    getPrime();
    cin >> N >> K;
    int arr[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    int currentNot = 0, p;
    bool isGood;
    for(int j = primes.size() - 1; j >= 0; j--){
        currentNot = 0;
        isGood = true;
        p = primes[j];
        for(int i = 0; i < N; i++){
            currentNot += (arr[i] % p != 0);
            //cout << arr[i] << "%" << p << " = " << arr[i]%p << endl;
            if(currentNot > K) {
                isGood = false;
                break;
            }
        }
        if(isGood){
            cout << p << endl;
            break;
        }
    }
    if(!isGood)
        cout << "NO" << endl;
}
