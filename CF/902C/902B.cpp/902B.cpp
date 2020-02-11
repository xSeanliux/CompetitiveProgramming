#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e4 + 10;

vector<int> parent;
vector<int> colour;
int n, t;

int main(){
    cin >> n;
    colour.resize(n);
    parent.resize(n);
    for(int i = 1; i < n; i++){
        cin >> t;
        t--;
        parent[i] = t;
    }
    for(int i = 0; i < n; i++){
        cin >> colour[i];
    }
    int ans = 1;
    for(int i = 1; i < n; i++) ans += (colour[i] != colour[parent[i]]);
    cout << ans << endl;

}
