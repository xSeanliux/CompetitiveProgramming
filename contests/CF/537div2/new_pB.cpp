#include <iostream>
#include <algorithm>
using namespace std;

long long int n, m, k, arr[100000], suf[100000];

int main(){
    cin >> n >> k >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    suf[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--) suf[i] = suf[i + 1] + arr[i];
    double maxAvg = -100;
    for(int i = min(m, n - 1); i >= 0; i--){ //means I will be deleting i elements
        long long int toDel = i, numsLeft = n - i, opsLeft = m - i;
        long long int currentSum = suf[i];
        currentSum += min(opsLeft, numsLeft * k);
        maxAvg = max(maxAvg, (currentSum + 0.00000000)/numsLeft);
    }
    printf("%.10lf\n", maxAvg);
}
