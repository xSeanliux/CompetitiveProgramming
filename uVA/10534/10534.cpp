#include <iostream>
#include <algorithm>
#define INF 2147483648
using namespace std;

int N;


int main(){
    while(cin >> N){
        long long int arr[N + 1], LIS[N + 1], LISB[N + 1], tmp[N + 1], tmpb[N + 1]; //LIS and LIS from Behind
        for(int i = 0 ; i < N; i++){
            cin >> arr[i];
            //cout << "a" << endl;
            tmp[i] = tmpb[i] = INF;
        }
        for(int i = 0 ; i < N; i++){
            *lower_bound(tmp, tmp + N, arr[i]) = arr[i];
            //cout << *lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin() << endl;
            LIS[i] = lower_bound(tmp, tmp + N, INF) - tmp;
            *lower_bound(tmpb, tmpb + N, arr[N - i - 1]) = arr[N - i - 1];
            LISB[N - i - 1] = lower_bound(tmpb, tmpb + N, INF) - tmpb;
        }
        long long int M = 0;
        for(int i = 0 ; i < N; i++){
            M = max(M, min(LIS[i], LISB[i]));
        }
        printf("%lld\n", 2*M-1);
    }
}
