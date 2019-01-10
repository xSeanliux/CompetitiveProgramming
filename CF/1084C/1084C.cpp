#include <iostream>
#include <string.h>
using namespace std;

string s;

int main(){
    cin >> s;
    int l = s.length();
    long long int ans[l], pre[l], lastb = -1;
    ans[0] = (s[0] == 'a');
    if(ans[0] == 'b') lastb = 0;
    pre[0] = ans[0];
    for(int i = 1; i < l; i++){
        if(s[i] == 'a'){
            if(lastb == -1){
                ans[i] = 1;
            } else {
                ans[i] = 1 + pre[lastb];
            }
        } else {
            ans[i] = 0;
            if(s[i] == 'b') lastb = i;
        }
        pre[i] = ans[i] + pre[i-1];
        pre[i] %= 1000000007;
        //cout << "pre[" << i << "] = " << pre[i] << endl;
    }
    printf("%lld\n", pre[l-1]);
}
