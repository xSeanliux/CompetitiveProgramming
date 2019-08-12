#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


vector<int> SA, nextrk, rk;
int gap, N;

bool cmp(int i, int j){
    if(rk[i] != rk[j]) return rk[i] < rk[j];

    i += gap;
    j += gap;

    if(i < N && j < N) return rk[i] < rk[j];
    else return i > j;
}

void getSA(string s){
    N = s.length();
    SA.resize(N);
    nextrk.resize(N);
    rk.resize(N);

    nextrk[0] = 0;

    for(int i = 0; i < N; i++){
        SA[i] = i;
        rk[i] = s[i] - 'a';
    }

    for(gap = 1;; gap *= 2){
        sort(SA.begin(), SA.end(), cmp);
        for(int i = 1; i < N; i++) nextrk[i] = nextrk[i-1] + cmp(SA[i - 1], SA[i]);
        for(int i = 0; i < N; i++) rk[SA[i]] = nextrk[i];
        if(nextrk[N - 1] == N - 1) break;
    }
}

string s;

int main(){
    cin >> s;
    getSA(s);
    for(int i : SA) cout << i << endl;
}
