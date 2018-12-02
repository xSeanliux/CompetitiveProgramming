#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

string convert(unsigned long long int N){
    //cout << "running convert(" << N << ")" << endl;
    if(!N) return "0";
    if(N == 1){
        return "2(0)";
    } else if(N == 2){
        return "2";
    } else {
        int hi = log2(N);
        //cout << hi << " of " << N << endl;
        if(N == pow(2, hi))
            return "2(" + convert(hi) + ")";
        if(hi == 1)
            return "2+" + convert(N - pow(2, hi));
        return "2(" + convert(hi) + ")+" + convert(N - pow(2, hi));
    }
}

unsigned long long int N;

int main(){
    //cout << convert((unsigned long long int)9223372036854775807) << endl;
    while(cin >> N){
        cout << convert(N) << endl;
    }
}

