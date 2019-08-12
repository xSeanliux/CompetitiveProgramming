#include <iostream>
using namespace std;

long long int N, maxp;

long long int fastexp(long long int b, long long int e){
    if(e == 1) return b;
    long long int res = fastexp(b, e/2);
    res = res * res;
    if(e % 2) res *= b;
    return res;
}

int main(){
    while(cin >> N){
        if(!N) return 0;
        maxp = 1;
        bool isNeg = (N < 0);
        if(N < 0) N = -N;
        for(int i = 2; i <= 32; i++){
            if ((long long)(1 << i) > N) break;
            for(int j = 2; fastexp(j, i) <= N; j++){
                //cout << "Checking " << j << " ^ " << i << " = " << fastexp(j, i) << endl;
                if(fastexp(j, i) == N) {
                    //printf("isNeg: %d, i: %d\n", isNeg, (i % 2));
                    if(isNeg) {
                        if(i % 2) maxp = i;
                    }
                    else maxp = i;
                }
            }
        }
        cout << maxp << endl;
    }
}
