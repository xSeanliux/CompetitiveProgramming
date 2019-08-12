#include <iostream>
#include <string.h>
#include <utility>
#include <map>
#define int long long int
#define pci pair<char,int>
using namespace std;

int vals[27], pre[(int)1e5 + 10];

string s;
map<pci, int> st;

signed main(){
    for(int i = 0; i < 26; i++) cin >> vals[i];
    cin >> s;

    pre[0] = 0;
    for(int i = 0; i < s.length(); i++){
        pre[i + 1] = pre[i];
        pre[i + 1] += vals[s[i] - 'a'];

        //cout << "pre[" << i + 1 << "] = " << pre[i + 1] << endl;
    }
    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        ans += st[{s[i], pre[i + 1] - 2 * vals[s[i] - 'a']}];
        //cout << "Adding st[" << s[i] << ", " << pre[i + 1] << "] to ans" << endl;
        st[{s[i], pre[i]}]++;
        //cout << "Inserting " << s[i] << ", " << pre[i] << endl;
    }
    cout << ans << endl;
}
