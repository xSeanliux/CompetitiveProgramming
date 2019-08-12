#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long int T, M, W;
vector<long long int> arr;
int main(){
    cin >> T;
    while(T--){
        cin >> M >> W;
        arr.clear();
        arr.resize(M);
        for(int i = 0; i < M; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        long long int sum = 0;
        for(int i = 0; i < M; i++){
            sum += arr[i];
            if(sum > W){
                cout << i << endl;
                break;
            }
            if(i == M - 1){
                cout << M << endl;
                break;
            }
        }
    }
}
