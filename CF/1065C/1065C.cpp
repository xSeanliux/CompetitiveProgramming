#include <iostream>
#include <vector>
using namespace std;

long long int N, K, x;
const long long  int lim = 2e5;
vector<long long int> vec;

int main(){
    scanf("%lld%lld", &N, &K);
    vec.reserve(lim + 10);
    vec.clear();
    vec[0] = N;
    long long int mval = lim, mxval = 0;
    for(int i = 0; i < N; i++){
        scanf("%lld", &x);
        mval = min(x, mval);
        mxval = max(x, mxval);
        vec[x + 1]--;
    }
    if(mval == mxval){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i <= lim; i++){
        vec[i] += vec[i-1];
    }

    long long int cuts = 0, sum = 0, ind = lim;
    while(ind > mval){
        cuts++;
        sum = 0;
        //cout << "Cut #" << cuts << endl;
        while(sum + vec[ind] <= K){
            sum += vec[ind--];
        }
    }
    printf("%lld\n", cuts);
}
