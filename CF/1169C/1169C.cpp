#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> vec;

inline int sub(int a, int b){
    return (a - b < 0) ? (a - b + M) : (a - b);
}

bool canDo(int moves){
    vector<int> _v;
    _v.resize(N);
    for(int i = 0; i < N; i++){
        _v[i] = vec[i];
    }
    if(M - _v[0] <= moves){
        _v[0] = 0;
    }
    for(int i = 1; i < N; i++){
        //try to get the same as last
        if(sub(_v[i - 1], _v[i]) <= moves){
            _v[i] = _v[i - 1];
        } else if(_v[i] >= _v[i - 1]) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

int main(){
    cin >> N >> M;
    vec.resize(N);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }
    int l = 0, r = M, m = l + r >> 1;
    while(l + 1 < r){
        if(canDo(m)){
            r = m;
        } else {
            l = m;
        }
        m = l + r >> 1;
        //cout << "l, r, m = " << l << ", " << r << ", " << m << endl;
    }
    for(int i = max(0, m - 2); i <= min(m + 2, M - 1); i++){
        //            cout << "Cando( " << i << ") = " << canDo(i) << endl;

        if(canDo(i)){
            cout << i << endl;
            return 0;
        }
    }
}
