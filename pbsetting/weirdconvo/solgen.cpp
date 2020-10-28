#include <iostream>
#include <vector>
#include <fstream>
#define int long long int
using namespace std;

string _dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/weirdconvo/", dir;

ifstream infile;
ofstream outfile;

const int maxN = 1e5 + 326;
int N, a[maxN], b[maxN], sda[maxN], sdb[maxN], mu[maxN];
vector<int> primes;
bool isPrime[maxN];

inline void sieve(){
	fill(isPrime, isPrime + maxN, 1);
	mu[1] = 1;
	for(int i = 2; i < maxN; i++){
		if(isPrime[i]){
			primes.push_back(i);
			mu[i] = -1;
		}
		for(int p : primes){
			if(p * i >= maxN) break;
			isPrime[p * i] = false;
			if(!(i % p)){
				mu[i * p] = 0;
				break;
			}
			mu[i * p] = -mu[i];
		}
	}
}

inline void solve(string folder, int tc){
	dir = _dir + folder + "/" + to_string(tc); 
	cout << "opening: " << dir << endl;
	outfile.open(dir + ".out");
	infile.open(dir + ".in");
	infile >> N;
	for(int i = 1; i <= N; i++) infile >> a[i];	
	for(int i = 1; i <= N; i++) infile >> b[i];
	for(int i = 1; i <= N; i++) sda[i] = sdb[i] = 0;
	for(int d = 1; d <= N; d++){ //N log N
		for(int i = d; i <= N; i += d){
			sda[d] += a[i];
			sdb[d] += b[i];
		}
	}
	for(int i = 1; i <= N; i++){
		int res = 0;
		for(int d = i; d <= N; d += i){
			res += sda[d] * sdb[d] * mu[d / i];
		}
		outfile << res << " ";
	}
	infile.close();
	outfile.close();
	cout << "Solved: " << folder << " / " << tc << endl;
}

signed main(){
	sieve();
	for(int t = 0; t <= 20; t++) solve("alltest", t);
}

