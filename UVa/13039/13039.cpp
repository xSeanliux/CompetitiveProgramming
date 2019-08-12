#include <iostream>
#include <vector>
using namespace std;

int T, N, t, ans, x, lastOne = 0;
vector<int> vec;
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        vec.clear();
        vec.resize(N);
        ans = 0, t = 0;
        for(int i = 0; i < N; i++){
            cin >> vec[i];
            ans += vec[i]/3;
            vec[i] %= 3;
            if(vec[i] == 1 && vec[i-1] >= 2){
                t -= 2;
                vec[i] = 0;
                vec[i-1] -= 2;
                ans++;
            }
            if(vec[i] == 2 && t){
                t--;
                vec[i] = 0;
                ans++;
            }
            t += vec[i];
        }
        cout << ans << endl;
    }
}
