#include <iostream>
#include <string.h>
using namespace std;

int K, ans;
string s;
bool has[10005];

int main(){
    while(cin >> K){
        ans = 0;
        for(int i = 0; i < 10000; i++) has[i] = false;
        if(!K) return 0;
        while(!has[K]){
            has[K] = true;
            s = to_string(K * K);
            while(s.length() < 8) s = '0' + s;
            K = stoi(s.substr(2, 4));
            ans++;
        }
        cout << ans << endl;
    }
}
