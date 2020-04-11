#include <iostream>
#include <vector>
#include <map>
#include <clock>
using namespace std;

const int maxN = 5e5 + 10, maxC = 1e6 + 10;

bool isPrime[maxC];
vector<int> primes;
map<int, int> mp;

void init(){
	fill(isPrime, isPrime + maxC, true);
	for(int i = 2; i < maxC; i++){
		if(isPrime[i]) primes.push_back(i);
		for(int p : primes){
			if(i * p >= maxC) continue;			
			isPrime[i * p] = false;
			if(!(i % p)) break;
		}
	}
}

int main(){
	init();
}
