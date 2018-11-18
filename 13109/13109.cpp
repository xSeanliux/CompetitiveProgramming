#include <iostream>
#include <algorithm>
using namespace std;

int c, nE, mW;

int weights[1000000  +5];

int main(){
    cin >> c;
    for(int k = 0; k < c; k++){
        if(k > 0) cout << endl;
        cin >> nE >> mW;
        for(int i = 0; i < nE; i++){
            cin >> weights[i];
        }
        sort(weights, weights + nE);
        long long int ans = 0, sum = 0;
        while(sum <= mW && ans <= nE){
            sum += weights[ans];
            ans++;
        }
        ans--;
        printf("%lld", ans);
    }
}
