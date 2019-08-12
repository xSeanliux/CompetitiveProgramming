#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> v;

int main(){
    bool hasE = false, hasO = false;
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
        if(v[i] % 2) hasO = true;
        else hasE = true;
    }
    if(hasO && hasE){
        sort(v.begin(), v.end());
    }
    for(int i : v) cout << i << " ";

}
