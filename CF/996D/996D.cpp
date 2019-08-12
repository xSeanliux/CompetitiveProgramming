#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> vals;

int main(){
    cin >> N;
    vals.resize(N * 2);
    int ans = 0;
    for(int i = 0; i < 2 * N; i++) cin >> vals[i];
    for(int i = 0; i < 2 * N; i += 2){
        if(vals[i] == vals[i + 1]) continue;
        vector<int> tmp;
        for(int j = 0; j < i; j++){
            tmp.push_back(vals[j]);
        }
        tmp.push_back(vals[i]);
        tmp.push_back(vals[i]);
        for(int j = i + 1; j < 2 * N; j++){
            if(vals[j] == vals[i]){
                ans += (j - i - 1);
                continue;
            }
            tmp.push_back(vals[j]);
        }

        for(int j = 0; j < 2 * N; j++){
            vals[j] = tmp[j];
        }
        //cout << endl;
    }
    cout << ans << endl;
}
