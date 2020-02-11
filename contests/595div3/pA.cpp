#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int q, n;
vector<int> vec;

int main(){
    cin >> q;
    while(q--){
        cin >> n;
        vec.resize(n);
        for(int i = 0; i < n; i++){
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        bool b = false;
        for(int i = 1; i < n; i++){
            if(vec[i] - vec[i - 1] == 1) b = true;
        }
        cout << 1 + b << endl;
    }
}
