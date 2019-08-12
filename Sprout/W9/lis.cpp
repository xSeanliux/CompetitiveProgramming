#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M, t;
vector<int> nums, newnum, lis;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        newnum.clear();
        lis.clear();
        for(int i = 0; i < N; i++){
            cin >> t;
            if(2 * t >= M){
                newnum.push_back(2 * t);
                lis.push_back(2147483647);
            }
            if(t >= M){
                newnum.push_back(t);
                lis.push_back(2147483647);
            }
        }
        //for(int i : newnum) cout << i << endl;
        for(int i = 0; i < newnum.size(); i++){
                *upper_bound(lis.begin(), lis.end(), newnum[i]) = newnum[i];
        }
        cout << lower_bound(lis.begin(), lis.end(), 2147483647) - lis.begin() << endl;
    }
}
