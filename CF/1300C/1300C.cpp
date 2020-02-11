#include <iostream>
using namespace std;

const int maxLog = 30, maxN = 1e5 + 226;

int cnt[30], vals[maxN], N, ans = 0, maxAt = 0, t;

int getAns(int ind){
    int res = 0;
    for(int j = 0; j < maxLog; j++){
        if(cnt[j] == 1 && ((vals[ind] & (1 << j)) > 0)) res += (1 << j);
    }
    return res;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> vals[i];
        for(int j = 0; j < maxLog; j++){
            cnt[j] += ((vals[i] & (1 << j)) >> j);
        }
    }
    for(int i = 0; i < N; i++){
        t = getAns(i);
        if(t > ans){
            ans = t;
            maxAt = i;
        }
    }
    cout << vals[maxAt];
    for(int i = 0; i < N; i++){
        if(i == maxAt) continue;
        cout << " " << vals[i];
    }
    cout << endl;
}
