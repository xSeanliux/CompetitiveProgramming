#include <iostream>
#include <math.h>
#include <vector>
#include <string.h>
#define int long long int
using namespace std;

int q, n, oneat;
vector<int> v;

signed main(){
    cin >> q;
    while(q--){
        cin >> n;
        v.resize(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(v[i] == 1) oneat = i;
        }
        bool cando = true;
        if(v[ (oneat + 1) % n ] == 2){
            for(int i = 0; i < n; i++){
                if(v[(oneat + i) % n] != i + 1){
                    cando = false;
                    break;
                }
            }
        } else if (v[ (oneat + n - 1) % n ] == 2){
            for(int i = 0; i < n; i++){
                if(v[(oneat - i + n) % n] != i + 1){
                    cando = false;
                    break;
                }
            }
        } else if(n > 1){
            cando = false;
        }
        cout << ((cando) ? "YES" : "NO") << endl;
    }

}
