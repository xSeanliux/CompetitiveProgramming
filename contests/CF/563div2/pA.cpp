#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int main(){
    cin >> N;
    v.resize(2 * N);
    for(int i = 0; i < 2 * N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int A = 0, B = 0;
    for(int i = 0; i < 2 * N; i++){
        (i < N ? A : B) += v[i];
    }
    if(A == B){
        cout << -1 << endl;
    } else {
        for(int i : v){
            cout << i << " ";
        }
    }
}
