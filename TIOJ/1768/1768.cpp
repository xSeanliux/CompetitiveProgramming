#include <iostream>
#include <vector>
using namespace std;

long long int N;
vector<long long int> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    v.resize(N);
    long long int sum = 0, wsum = 0;
    for(long long int i = 0; i < N; i++){
        cin >> v[i];
        sum += v[i];
        wsum += v[i] * i;
    }
    long long int i = 0;
    for(i = 0; (wsum % sum) > 0 && i < N/2; i++){
        wsum = wsum - v[i] * i - v[N - 1 - i] * (N - 1 - i) + v[i] * (N - i - 1) + v[N - 1 - i] * i;
    }
    cout << i << " " << wsum/sum << endl;
}





