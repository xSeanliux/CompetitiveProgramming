#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N, t;
vector<int> a;
map<int, int> b;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++){
        cin >> t;
        b[t]++;
    }
    int x, y;
    for(int i = 0; i < N; i++){
        //search n - a[i] and 0
        auto px = b.lower_bound(N - a[i]), py = b.lower_bound(0);
        //cout << px->first << ", " << py->first << endl;
        x = (px == b.end() ? N - a[i] - 1 : px->first);
        y = (py == b.end() ? N - a[i] - 1 : py->first);
        //cout << "x = " << x << ", y = " << y << endl;

        if((x + a[i]) % N < (y + a[i]) % N){ //use x
            cout << (x + a[i]) % N << " ";
            px->second--;
            if(!px->second) b.erase(px);
        } else { //use y
            cout << (y + a[i]) % N << " ";
            py->second--;
            if(!py->second) b.erase(py);
        }

    }
    cout << endl;
}
