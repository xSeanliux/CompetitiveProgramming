#include <iostream>
#include <algorithm>
#include <set>
#include <string.h>
using namespace std;

string ans = "";
    int N;
bool isPal(string &x){
    string _x = x;
    reverse(_x.begin(), _x.end());
    return x == _x;
}

int numpal(){
    set<string> st = set<string>();
    for(int i = 0; i < N; i++){
        for(int j = 1; j + i <= N; j++){
            string _s = ans.substr(i, j);
            if(isPal(_s)) st.insert(_s);
        }
    }
    return st.size();
}

int main() {

    cin >> N;
    while((int)ans.size() < N){
        ans += "110100";
    }
    ans = ans.substr(0, N);
    cout << numpal() << endl;
    cout << ans << endl;
}   
