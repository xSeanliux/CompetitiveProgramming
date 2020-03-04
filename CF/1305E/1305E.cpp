#include <iostream>
#include <vector>
using namespace std;

int n, m, cur;
vector<int> ans;
int main(){
    cin >> n >> m;
    if(n <= 2){
        if(m == 0){
            for(int i = 1; i <= n; i++) cout << i << " ";
            cout << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    if((n - 1) / 2 * ((n - 1) / 2 + 1) < m){
        cout << -1 << endl;
        return 0;
    }
    ans.push_back(1);
    ans.push_back(2);
    for(int i = 3; i <= n; i++){
        if(((i - 1) / 2) > m){
            ans.push_back(2 * i  - 1 - 2 * m);
            //still n - ans.size() numbers left
            int k = n - ans.size();
            for(int j = k; j; j--) ans.push_back(1000000000 - j * n);
            break;
        } else {
            ans.push_back(i);
            m -= (i - 1) / 2;
        }
    }
    for(int x : ans) cout << x << " ";
    cout << endl;
}
