#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

int T, N, M;
vector <int> arr;
string s;

int main(){
    cin >> N >> s;
    string ans = "";
    int ind = 0, counter = 1;
    while(ind < N){
        ans += s[ind];
        ind += counter;
        counter++;
    }
    cout << ans << endl;

}
