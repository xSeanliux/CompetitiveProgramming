#include <iostream>
#include <string.h>
#include <vector>
#define int long long int
using namespace std;

string s;

int n, ans;
vector<int> v;

signed main(){
    cin >> n >> s;
    char c;
    int cnt = 0, ans = n * (n - 1) / 2;
    //cout << ans << endl;
    for(int i = 0; i < n; i++){
        c = s[i];
        cnt = 0;
        while(i < n && s[i] == c){
            i++;
            cnt++;
        }
        i--;
        v.push_back(cnt);
        //cout << cnt << endl;
    }
    for(int i = 1; i < v.size(); i++){
        ans -= v[i];
        ans -= v[i - 1];
        ans += 1;
    }
    cout << ans << endl;

}
