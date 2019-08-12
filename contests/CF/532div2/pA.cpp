#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int n, a, b, k;
int arr[105], tarr[105];
string s;

int main(){
    cin >> n >> k;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        tarr[i] = arr[i];
    }
    for(int i = 0; i < n; i++){//i is the period
        //cout << i << endl;
        for(int j = 1; j <= n; j++){
            tarr[j] = arr[j];
        }
        for(int j = 1; j <= n; j++){
            if(j % k == i) tarr[j] = 0;
        }
        int cans = 0;
        for(int j = 1; j <= n; j++){
            cans += tarr[j];
        }
        if(cans < 0) cans = -cans;
        ans = max(cans, ans);
        //cout << "A" << ans << endl;
    }
    cout << ans << endl;
}
