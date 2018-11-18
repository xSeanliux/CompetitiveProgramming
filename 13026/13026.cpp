#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

string ans, cS;
string possible[1000000];
int c, N, diffs, head;

int main(){
    cin >> c;
    for(int ia = 1; ia <= c; ia++){
        cin >> N >> ans;
        head = 0;
        int l = ans.length();
        for(int i = 0; i < N; i++){
            cin >> cS;
            diffs = 0;
            for(int i = 0 ; i < l; i++){
                if(cS[i] != ans[i]){
                    diffs++;
                    //cout << cS[i] << " - " << ans[i] << " = " << cS[i] - ans[i] << endl;
                    if(diffs > 1  || abs(cS[i] - ans[i]) > 1){
                        diffs = 2;
                    }
                }
            }
            if(diffs >= 1){
                possible[head] = cS;
                head++;
            }
        }
        //sort(possible, possible + head);
        printf("Case %d:\n", ia);
        cout << ans << endl;
        for(int i = 0 ; i < head;i ++){
            cout << possible[i] << endl;
        }
    }
}
