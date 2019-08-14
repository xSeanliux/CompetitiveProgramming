#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int q, n;
vector<int> v;

int main(){
    cin >> q;
    while(q--){
        cin >> n;
        v.resize(4 * n);
        for(int i = 0; i < 4 * n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        vector<int> vec;
        bool cando = true;
        for(int i = 0; i < 4 * n; i += 2){
            if(v[i] == v[i + 1]){
                vec.push_back(v[i]);
            } else {
                cando = false;
                break;
            }
        }

        if(!cando){
            cout << "NO" << endl;
            continue;
        }

        int area = vec[0] * vec[2 * n - 1];

        for(int i = 1; i < n; i++){ //ith
            if(vec[i] * vec[2 * n - 1 - i] != area){
                cando = false;
                break;
            }
        }

        if(!cando){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}


