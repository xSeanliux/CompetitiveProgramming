#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
void Report(long long int i){
    cout << i << endl;
}
*/
void solve(int N,long long K,long long A[]){
    map<long long int, vector<long long int> > l, r;
    vector<long long int> lV, rV;
    for(int i = 0; i < N; i++){
        (i < N/2 ? lV : rV).push_back(A[i]);
    }
    long long int sum;
    vector<long long int> v;
    for(int i = 0; i < (1 << lV.size()); i++){
        sum = 0;
        v.clear();
        for(int j = 0; j < lV.size(); j++){
            if(i & (1 << j)){
                sum += lV[j];
                v.push_back(j + 1);
            }
        }
        l.insert({sum, v});
    }
    for(int i = 0; i < (1 << rV.size()); i++){
        sum = 0;
        v.clear();
        for(int j = 0; j < rV.size(); j++){
            if(i & (1 << j)){
                sum += rV[j];
                v.push_back(j + 1 + N/2);
            }
        }
        if(l.count(K - sum)){
            for(long long int i : v){
                Report(i);
            }
            for(long long int i : l[K - sum]){
                Report(i);
            }
            Report(-1);
            return;
        }
    }
}


