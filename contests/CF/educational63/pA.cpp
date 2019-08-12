#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
using namespace std;

int T, N, K, x, y, a, b;
string s;
vector<int> vec;

int main(){
    cin >> N >> s;
    for(int i = 1; i < N; i++){
        if(s[i] < s[i - 1]){
            cout << "YES" << endl;
            cout << i << " " << i + 1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
