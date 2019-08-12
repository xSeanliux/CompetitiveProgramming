#include <iostream>
using namespace std;

int N, r;
bool vals[1010];

int main(){
    cin >> N >> r;
    int ans = 0;
    for(int i = 0; i < N; i++) cin >> vals[i];
    for(int i = 0; i < N; i++){ //currentLeft = i
        for(int j = min(i + r - 1, (int)(N - 1)); j >= i -r + 1 && j >= 0; j--){
            if(vals[j]){
                i = j + r - 1;
                //cout << "place at" << j << endl;
                ans++;
                if(i >= N){
                    cout << ans << endl;
                    return 0;
                }
                break;
            } else if(j == i - r + 1 || j <= 0){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
}
