#include <iostream>
#include <string.h>
using namespace std;

const int maxN = 1e3 + 326;

string ans[maxN];
int arr[maxN];

string f(int x, int &plus) { //calculates the length of x
    string bin = ""; 
    while(x) {
      bin = (char)('0' + (x & 1)) + bin;
      x /= 2;
    }
    string ret = "1";
    for(int i = 1; i < bin.size(); i++){
        ret += "d+"; 
        plus++;
        if(bin[i] == '1') {
            ret += "1+";
            plus++;
        }
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    int delt = 0;
    for(int i = N - 1; i >= 0; i--) {
        ans[i] = f(arr[i] + delt, delt);
    }
    for(int i = 0; i < N; i++) cout << ans[i];
    cout << endl;
}
