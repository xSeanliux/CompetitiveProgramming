#include <iostream>
#include <math.h>
#define int long long int
using namespace std;

long long int szs[7] = {0}, ans;

signed main(){
    while(cin >> szs[1]){
        int _sum = szs[1];
        for(int i = 2; i <= 6; i++){
            cin >> szs[i];
            _sum += szs[i];
        }
        if(!_sum) return 0;
        ans = 0;
        ans += szs[6];
        //cout << "Finished packing SZ = 6, ans = " << ans << endl;

        //cout << endl;
        szs[6] = 0;
        for(int i = 1; i <= 6; i++){
        //    cout << szs[i] << " ";
        }
        ans += szs[5];
        szs[1] = max(0LL, szs[1] - 11 * szs[5]);
        szs[5] = 0;
        //cout << "Finished packing SZ = 5, ans = " << ans << endl;
        for(int i = 1; i <= 6; i++){
        //    cout << szs[i] << " ";
        }
        //cout << endl;
        if(5 * szs[4] > szs[2]){ //start fitting in szs[1]
            szs[2] = 0;
            szs[1] = max(0LL, szs[1] - 4*(5*szs[4] - szs[2]));
        } else {
            szs[2] -= 3 * szs[4];
        }
        ans += szs[4];
        //cout << "Finished packing SZ = 4, ans = " << ans << endl;
        szs[4] = 0;
        for(int i = 1; i <= 6; i++){
        //    cout << szs[i] << " ";
        }
        //cout << endl;
        ans += szs[3]/4;
        szs[3] %= 4;
        if(szs[3] == 1){
            if(szs[2] > 5){
                szs[2] -= 5;
                szs[1] = max(0LL, szs[1] - 7);
            } else {
                szs[2] = 0;
                szs[1] = max(0LL, szs[1] - (27 - 4*szs[2]));
            }
        } else if(szs[3] == 2){
            if(szs[2] > 3){
                szs[2] -= 3;
                szs[1] = max(0LL, szs[1] - 6);
            } else {
                szs[2] = 0;
                szs[1] = max(0LL, szs[1] - (18 - 4*szs[2]));
            }
        } else if(szs[3] == 3){
            if(szs[2] > 1){
                szs[2] -= 1;
                szs[1] = max(0LL, szs[1] - 5);
            } else {
                szs[2] = 0;
                szs[1] = max(0LL, szs[1] - 4*szs[2]);
            }
        }
        if(szs[3]) ans++;
        //cout << "Finished packing SZ = 3, ans = " << ans << endl;
        //packing 2 and 1
        ans += szs[2]/9;
        szs[2] %= 9;
        for(int i = 1; i <= 6; i++){
            //cout << szs[i] << " ";
        }
        //cout << endl;
        if(szs[2] + szs[1] == 0){
            printf("%d\n", ans);
            continue;
        }
        ans += szs[2] / 9;
        szs[2] %= 9;
        if(szs[2]){
            ans++;
            szs[1] = max(0LL, szs[1] - (36 - 4*szs[2]));
        }
        ans += ceil((szs[1] + 0.0)/36.0);
        //ans += ceil((szs[2] * 4 + szs[1] + 0.0)/36.0);
        //cout << "Finished packing SZ = 2, ans = " << ans << endl;
        printf("%lld\n", ans);
    }
}
