#include <iostream>
#include <math.h>
#include <map>
#include <string.h>
#define ulli unsigned long long int
using namespace std;



unsigned long long int A, B, K, C = 0;
int T;


map<string, ulli> mp;

ulli getAns(ulli upRow, ulli downRow, ulli ite){
    string s = to_string(upRow) + '/' + to_string(downRow) + '/' + to_string(ite);
    //printf("Running Row %llu to %llu of iteration %llu\n", upRow, downRow, ite);
    if(mp.count(s)){
        //printf("mem: Row %llu to %llu of iteration %llu has %llu red balloons\n", upRow, downRow, ite, mp[s]);
        return mp[s];
    }
    if(ite == 0) return 1;
    ulli ans = 0;
    if(downRow > pow(2, ite-1)){
        if(upRow > pow(2, ite - 1)){
            ans = getAns(upRow - pow(2, ite - 1), downRow - pow(2, ite - 1), ite - 1);
        } else {
            ans = getAns(1, downRow - (pow(2, ite-1)), ite-1) + 2*getAns(upRow, pow(2, ite-1), ite-1);
        }
    } else {
        ans = 2*getAns(upRow, downRow, ite-1);
    }
    mp.insert(pair<string, ulli>(s, ans));
    //cout << s << ":  " << ans << endl;
    return mp[s];
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%llu %llu %llu", &K, &A, &B);
        printf("Case %d: %llu\n", ++C, getAns(A, B, K));
    }
}
