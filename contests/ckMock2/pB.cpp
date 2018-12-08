#include <iostream>
#define MOD 1000000009
using namespace std;
/*
long long int fact[10005], stuff[10005];

void getFact(){
    fact[0] = 1;
    for(int i = 1; i <= 10000; i++){
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }
}

void getAn(){
    stuff[0] = 1;
    for(int i = 1; i <= 10000; i++){
        stuff[i] = 0;
        for(int j = 0; j < i; j++){
            stuff[i] += fact[i-j-1] * stuff[j];
            stuff[i] %= MOD;
            //cout << "stuff[" << i << "] += fact[" << i - j << "] * a_" << j << endl;
        }
    }
}
int N, X;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while(N--){
        cin >> X;
        cout << stuff[X] << endl;
    }
}
