#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 22625 * 2;

vector<int> adj[maxN];
int n, x, t;

int main(){
    ericxiao;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        while(x--){
            cin >> t;
            adj[i].push_back(t);
        }
    }

}
