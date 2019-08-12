#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int N, Q, x;
vector<long long int> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    v.resize(N + 2);
    v[0] = -1;
    for(int i = 1; i <= N; i++) cin >> v[i];
    v[N + 1] = 1LL << 33;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> x;
        long long int uval = *upper_bound(v.begin(), v.end(), x), lval = *(lower_bound(v.begin(), v.end(), x)-1);
        if(lval > 0){
            cout << lval;
        } else {
            cout << "X";
        }
        cout << " ";
        if(uval <= 1LL << 32){
            cout << uval;
        } else {
            cout << "X" << endl;
        }
        cout << endl;
    }
}
