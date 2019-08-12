#include <iostream>
using namespace std;

int n, k, modNum[1000], x, ans;

int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        modNum[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        modNum[x % k]++;
    }
    ans = modNum[0]/2;
    for(int i = 1; i < k/2; i++){
        ans += min(modNum[i], modNum[k - i]);
    }
    if(k % 2 == 0){
        ans += modNum[k/2]/2;
    } else {
        ans += min(modNum[k/2], modNum[k - k/2]);
    }
    cout << 2*ans << endl;
}
