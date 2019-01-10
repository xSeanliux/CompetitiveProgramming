#include <iostream>
using namespace std;

int day, month, cY, tY, c, ans;

bool isLeap(int year){
    if(!(year % 400)) return true;
    else if(!(year % 100)) return false;
    else if(!(year % 4)) return true;
    return false;
}

int main(){
    cin >> c;
    for(int k = 1; k <= c; k++){
        //if(k > 1) printf("\n");
        cin >> day >> month  >> cY >> tY;
        printf("Case %d: ", k);
        if(cY == tY){
            ans = 0;
        } else {
            if(day == 29 && month == 2){
                ans = 0;
                for(int i = cY + 4 - (cY % 4); i <= tY; i += 4 ){
                    ans += isLeap(i);
                }
            } else {
                ans = tY - cY;
            }
        }

        printf("%d\n", ans);

    }
}
