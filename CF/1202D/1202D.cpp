#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define int long long int
using namespace std;

int t, N;
vector<int> f, v;

signed main(){
    cin >> t;
    while(t--){
        cin >> N;
        v.clear();
        f.clear();
        for(int k = 1; k <= N; k++){
            if((2 * k - 1) * k > N) break;
            f.push_back((2 * k - 1) * k);
            //cout << "Push: " << (2 * k - 1) * k << endl;
        }
        int a = N;
        reverse(f.begin(), f.end());
        v.resize(f.size());
        for(int i = 0; i < f.size(); i++){
            v[i] = a / f[i];
            //cout << "v[" << i << "] = " << v[i] << endl;
            a %= f[i];
            //cout << "a now " << a << endl;
        }
        for(int i = 0; i < f.size(); i++){
            for(int j = 0; j < v[i]; j++){
                cout << 1;
            }
            cout << 33;
        }
        cout << 7 << endl;
    }

}
