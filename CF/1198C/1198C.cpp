#include <iostream>
#include <unordered_set>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

int t, n, m, a, b;
unordered_set<int> usedVertices;
vector<int> match;
int main(){
    ericxiao
    cin >> t;
    while(t--){
        match.clear();
        usedVertices.clear();
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            if(!usedVertices.count(a) && !usedVertices.count(b) ){
                match.push_back(i + 1);
                usedVertices.insert(a);
                usedVertices.insert(b);
            }
        }
        if(match.size() >= n){
            cout << "Matching" << endl;
            for(int i = 0; i < n; i++){
                cout << match[i] << " \n"[i == n - 1];
            }
        } else {
            int cnt = 0;
            cout << "IndSet" << endl;
            for(int i = 1; i <= 3 * n && cnt < n; i++){
                if(!usedVertices.count(i)) cout << i << " \n"[++cnt == n];
            }
        }
    }
}
