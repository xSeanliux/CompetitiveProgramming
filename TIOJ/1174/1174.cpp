#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int N, M;

int main(){
    while(cin >> N >> M){
        if(N > M) swap(N, M);
        int arr1[N + 1], arr2[M + 1];
        for(int i = 0; i < N; i++){
            cin >> arr1[i];
        }
        for(int i = 0; i < M; i++){
            cin >> arr2[i];
        }
        sort(arr2, arr2 + M); //only arr2 needs to be sorted
        int currentAns = 2147483647;
        for(int i = 0; i < N; i++){
            int ind = lower_bound(arr2, arr2 + M, arr1[i]) - arr2;
            //cout << arr2[ind] << endl;
            //cout << "Found: " << arr2[ind] << ", checking for the value " << arr1[i] << endl;
            if(ind > 0){
                currentAns = min(currentAns, min(abs(arr1[i] - arr2[ind]), abs(arr1[i] - arr2[ind-1])));
            } else {
                currentAns = min(currentAns, abs(arr1[i] - arr2[ind]));
            }
        }
        cout << currentAns << endl;
    }
}
