#include <iostream>
#include <vector>
#include <set>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


int N;
vector<int> vec;

signed main(){
    ericxiao;
    cin >> N;
    vec.resize(N);
    int sum = 0;
    multiset<int> st;
    st.insert(0);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
        sum += vec[i];
        st.insert(vec[i]);
    }
    if(sum % 2){
        cout << "NO" << endl;
        return 0;
    }
    int lSum = 0, rSum = sum;
    if(lSum == rSum){
        cout << "YES" << endl;
        return 0;
    }
    int delta;
    for(int i = 0; i < N; i++){
        delta = rSum - lSum;
        //cout << "Delta = " << delta << endl;
        if(delta % 2 == 0 && st.count(delta/2)){
            cout << "YES" << endl;
            return 0;
        }
        rSum -= vec[i];
        lSum += vec[i];
        st.erase(st.find(vec[i]));
        st.insert(-vec[i]);
    }
    cout << "NO" << endl;
}
