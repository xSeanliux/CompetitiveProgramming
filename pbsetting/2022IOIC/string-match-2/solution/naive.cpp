#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


int main() {
    int N, Q, l, r;
    string S;

    cin >> N >> Q >> S;

    while(Q--) {
        cin >> l >> r;
        l--;
        int _len = r - l;
        string a = S.substr(l, _len);
        for(int i = 0; i + _len <= N; i++) {
            string b = S.substr(i, _len);
            if(a == b) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }

}
