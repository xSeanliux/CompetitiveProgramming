#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> vals, x, y;

int main(){
    cin >> N;
    vals.resize(N);
    for(int i = 0; i < N; i++) cin >> vals[i];
    sort(vals.begin(), vals.end());
    x.clear();
    y.clear();
    for(int i : vals){
        if(!x.size()) x.push_back(i);
        else if(!y.size()) y.push_back(i);
        else {
            if(i == x[x.size() - 1]){
                if(i == y[y.size() - 1]){
                    cout << "NO" << endl;
                    return 0;
                } else {
                    y.push_back(i);
                }
            } else {
                x.push_back(i);
            }
        }
    }
    cout << "YES" << endl;
    cout << x.size() << endl;
    for(int i : x) cout << i << " ";
    cout << endl;
    cout << y.size() << endl;
    reverse(y.begin(), y.end());
    for(int i : y) cout << i << " ";
}
