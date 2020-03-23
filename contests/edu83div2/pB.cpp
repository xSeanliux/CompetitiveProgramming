#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
vector<int> vec;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        vec.clear();
        vec.resize(N);
        for(int i = 0; i < N; i++) cin >> vec[i];
        sort(vec.begin(), vec.end(), greater<int>());
        for(int x : vec) cout << x << " ";
        cout << endl;
    }
}
