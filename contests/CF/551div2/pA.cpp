#include <iostream>
#include <set>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

long long int T, N, K, a, b;
string s;

long long int minVal, minAt;

int main(){
    cin >> N >> K;
    minVal = (long long int)1e10;
    int times[(int)1e6 + 10];
    for(int i = 0; i < (int)1e6 + 10; i++) times[i] = -1;
    for(int i = 1; i <= N; i++){
        cin >> a >> b;
        for(int j = a; j < (int)1e6 + 10; j += b){
            times[j] = i;
        }
    }
    for(int i = K;; i++){
        if(times[i] != -1){
            cout << times[i] << endl;
            return 0;
        }
    }
}
