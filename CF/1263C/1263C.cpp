#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v;
        for(int i = 1; i <= n; i++){
            v.push_back(n/i);
            i = n / (n / i);
        }
        v.push_back(0);
        reverse(v.begin(), v.end());
        cout << v.size() << endl;
        for(int u : v) cout << u << " ";
        cout << endl;
    }
}
