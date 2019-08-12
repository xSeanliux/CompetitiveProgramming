#include <iostream>
#include <string.h>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

string s;
long long int N, x;
set<long long int> st;
const long long int INF = 2147483647;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    st.insert(INF); st.insert(-INF);
    while(N--){
        cin >> s >> x;
        if(s == "insert")
            st.insert(x);
        else if(s == "delete")
            st.erase(x);
        else {
            auto lP = st.lower_bound(x), rP = st.upper_bound(x);
            if(*lP != x) lP--;
            if(x - *lP == *rP - x) cout << *lP << " " << *rP << '\n';
            else cout << ((x - *lP < *rP - x) ? *lP : *rP) << '\n';
        }
    }
}
