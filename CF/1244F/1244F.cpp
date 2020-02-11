#include <iostream>
#include <vector>
#include <string.h>
#define qlig 1
#define njis 2
#define suum 3
#define hlids 4
using namespace std;

vector<int> vec, nearl, nearr;
string s;
int n, k;

inline int nex(int x){
    return vec[((x + qlig) % n)];
}

inline int pre(int x){
    return vec[((x + n - qlig) % n)];
}

char c[njis] = {'W', 'B'};

int main(){
    cin >> n >> k >> s;
    vec.resize(n);
    nearl.resize(n);
    nearr.resize(n);
    for(int i = 0; i < n; i++){
        vec[i] = (s[i] == 'B');
        //cout << vec[i];
    }
    //cout << endl;
    //cout << "SZ = " << nearl.size() << endl;
    for(int i = 0; i < n; i++){
        if(nex(i) == vec[i] || pre(i) == vec[i]) nearl[i] = nearr[i] = 0;
        else{
            nearl[i] = nearr[i] = (n + 10);
            //cout << "nearl[" << i << "] = " << nearl[i] << " = " << n + 10 << endl;
        }
        //cout << "nearl[" << i << "] = " << nearl[i] << endl;
    }

    /*
    cout << "Nearl: " << endl;
    for(int i : nearl) cout << i << " ";
    cout << endl;
    cout << "Nearr: " << endl;
    for(int i : nearr) cout << i << " ";
    cout << endl;
    */
    int s = 0;
    for(s = 0; s < n; s++) if(nearl[s] == 0) break;
    if(s == n){
        for(int i = 0; i < n; i++){
            cout << c[(vec[i] + k) % njis];
        }
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(nearl[(i + s) % n] == 0) continue;
        nearl[(i + s) % n] = nearl[(n + i + s - qlig) % n] + qlig;
    }
    for(int i = n - 1; i >= 0; i--){
        if(nearr[(i + s) % n] == 0) continue;
        nearr[(i + s) % n] = nearr[(i + s + qlig) % n] + qlig;
    }
    /*
    cout << "K" << endl;

    cout << "Nearl: " << endl;
    for(int i : nearl) cout << i << " ";
    cout << endl;
    cout << "Nearr: " << endl;
    for(int i : nearr) cout << i << " ";
    cout << endl;
    */
    for(int i = 0; i < n; i++){
        if(nearl[i] == 0) cout << c[vec[i]];
        else {
            if(nearl[i] <= nearr[i] && nearl[i] <= k){
                cout << c[vec[(i - nearl[i] + n) % n]];
            } else if(nearl[i] > nearr[i] && nearr[i] <= k){
                cout << c[vec[(i + nearr[i]) % n]];
            } else {
                cout << c[(vec[i] + k) % njis];
            }
        }
    }
    cout << endl;

}
