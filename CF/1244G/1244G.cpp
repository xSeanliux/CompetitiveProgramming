#include <iostream>
#include <vector>
#include <numeric>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, k;
vector<int> perm;
vector<bool> visited;

signed main(){
    cin >> n >> k;
    perm.resize(n);
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);
    iota(perm.begin(), perm.end(), 1);
    /*
    for(int i : perm){
        cout << i << " ";
    }
    cout << endl;
    */
    int sum = n * (n + 1) / 2;
    if(sum > k){
        cout << -1 << endl;
        return 0;
    }
    int c = 0;
    for(int i = n - 1; i >= 0; i--){
        while(c < i && sum + (i - c) > k){
            c++;
        }
        //cout << "Looking at " << i << " and " << c << endl;
        if(c >= i) break;
        else {
            //cout << "SWAP" << endl;
            sum += (i - c);
            swap(perm[i], perm[c]);
            c++;
            /*
            for(int i : perm){
                cout << i << " ";
            }
            cout << endl;
            */
        }
    }
    cout << sum << endl;
    for(int i = 1; i <= n; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i : perm){
        cout << i << " ";
    }
    cout << endl;

}
