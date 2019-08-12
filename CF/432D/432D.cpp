#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

string s;

const int maxN = 1e5;
int bit[maxN + 10], N;


void add(int p){
    for(int i = p; i <= N; i += (i & -i)){
        bit[i]++;
    }
}

int query(int p){
    int ans = 0;
    for(int i = p; i > 0; i -= (i & -i)){
        ans += bit[i];
    }
    return ans;
}


vector<int> z_algorithm(string s) {
    int n = s.length();
    vector <int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
// if we've gone outside the current z-box, start a new one
        if (i >= r) {
            l = r = i;
            while (s[r - l] == s[r]) r++;
            z[i] = r - l;
        } else {
            int k = i - l;
// if we can use already computed information , do so
            if (z[k] < r - i) z[i] = z[k];
// otherwise , expand the z-box as much as possible
            else {
                l = i;
// we don't need to reset r because we already know the string
                //matches earlier
                while (s[r - l] == s[r]) r++;
                z[i] = r - l;
            }
        }
    }
    z[0] = n;
    return z;
}

int main(){
    cin >> s;
    N = s.length();
    vector<int> z = z_algorithm(s);
    fill(bit, bit + N + 10, 0);
    for(int i : z){
        if(i) add(i);
    }
    vector<pii> ans;
    string pre = "", suf = "";
    for(int i = N - 1; i >= 0; i--){
        //cout << pre << ", " << suf << endl;
        if(i + z[i] == N){ //naive string comparison will TLE
            ans.push_back({z[i], query(N) - query(z[i] - 1)});
        }
    }
    cout << ans.size() << endl;
    for(auto p : ans){
        cout << p.F << " " << p.S << endl;
    }
}
