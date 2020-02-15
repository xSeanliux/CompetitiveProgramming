#include <iostream>

using namespace std;

const int maxN = 1e5 + 10;

int arr[maxN], N, T;

int can(int x){
    int minR = 1e9, maxL = 0;
    for(int i = 0; i < N; i++){
        if(arr[i] == -1){
            if(i && (arr[i - 1] != -1)){
                minR = min(minR, arr[i - 1] + x);
                maxL = max(maxL, arr[i - 1] - x);
            }
            if((i < N - 1) && (arr[i + 1] != -1)){
                minR = min(minR, arr[i + 1] + x);
                maxL = max(maxL, arr[i + 1] - x);
            }
        }
    }
    if(minR >= maxL) return maxL;
    else return -1;
}

inline int Abs(int x){
    return x < 0 ? -x : x;
}

void solve(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    int l = -1, r = 1e9 + 10, m, res;
    while(l + 1 < r){
        m = (l + r) / 2;
        res = can(m);
        if(res == -1) l = m;
        else r = m;
    }
    res = can(r);
    for(int i = 0; i < N; i++)
        if(arr[i] == -1) arr[i] = res;

    for(int i = 0; i < N - 1; i++) m = max(m, Abs(arr[i] - arr[i + 1]));
    cout << m << " " << res << endl;
}

int main(){
    cin >> T;
    while(T--) solve();
}
