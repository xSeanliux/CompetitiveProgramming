#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> v;

int main(){
    cin >> n >> k;
    v.resize(n);
    int res = 0;
    for(int i = 0; i < n; i++) cin >> v[i];
    int curInd = n - 1;
    for(int t = k; t >= 1; t--){
        int curSum = v[curInd], maxSum = 0, maxInd = curInd;
        while(curSum > 0 && curInd > t - 2){
            curSum +=
        }
    }
}
