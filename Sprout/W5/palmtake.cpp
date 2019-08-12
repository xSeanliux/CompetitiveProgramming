#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, n, m, bags[(int)1e5 + 10], stuff[(int)1e5 + 10];
int main(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> bags[i];
        for(int i = 0; i < m; i++) cin >> stuff[i];
        sort(bags, bags + n);
        sort(stuff, stuff + m);
        int ans = 0, ind = 0;
        for(int i = 0; i < n; i++){
            while(stuff[ind] <= bags[i]){
                bags[i] -= stuff[ind++];
                //cout << "BAG " << i << " PUT stuff[" << ind - 1 << "]" << endl;
                //cout << "BAG " << i << " has " << bags[i] << " cap" << endl;
                //cout << "NOW TRYING TO PUT " << stuff[ind] << endl;
                ans++;
                if(ind == m) break;
            }
            //cout << "MOV" << endl;
            if(ind == m) break;
        }
        cout << ans << endl;
    }
}
