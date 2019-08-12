#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> v, dif;
int main(){
    cin >> n >> k;
    v.resize(n);
    dif.resize(n - 1);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i){
            dif[i - 1] = v[i] - v[i - 1];
        }
    }
    sort(dif.begin(), dif.end());
    int ans = 0;
    for(int i = 0; i < n - k; i++){
        ans += dif[i];
    }
    cout << ans << endl;
}
