#include <iostream>
#include <algorithm>
#define int long long int
using namespace std;

const int maxL = 60;

inline int lg(int x){
    for(int i = 0;; i++){
        if((x >> i) & 1) return i;
    }
}

int t, n, m, x, boxes[maxL], sum, has[maxL], ans, allsum;

signed main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        sum = allsum = ans = 0;
        for(int i = 0; i < maxL; i++) has[i] = boxes[i] = 0;
        for(int i = 0; i < maxL; i++){
            if((n >> i) & 1) has[i] = true;
        }
        for(int i = 0; i < m; i++){
            cin >> x;
            allsum += x;
            boxes[lg(x)]++;
        }
        /*
        for(int i = 0; i < 10; i++){
            cout << has[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < 10; i++){
            cout << boxes[i] << " ";
        }
        cout << endl;
        */
        if(allsum < n){
            cout << -1 << endl;
            continue;
        }
        for(int i = 0; i < maxL; i++){
            if(has[i]) {
                if(sum >= (1LL << i)){
                    sum -= (1LL << i);
                } else {
                    if(!boxes[i]) {
                        for(int j = i; j < maxL; j++){
                            if(boxes[j]){
                                ans += (j - i);
                                for(int k = i; k < j; k++){
                                    boxes[k]++;
                                }
                                boxes[j]--;
                                break;
                            }
                        }
                    }
                    boxes[i]--;
                }
            }
            sum += (1LL << i) * boxes[i];
        }
        cout << ans << endl;
    }
}

