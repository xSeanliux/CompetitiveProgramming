#include <iostream>
#include <math.h>
using namespace std;

int maxN[203];
int year;


int main(){
    while(cin >> year){
        if(!year) return 0;
        double sum = 0; //exit when sum >
        int j = 1;
        int ans = 0;
        while(sum <= pow(2, year/10 - 194)){
            sum += log2(j);
            j++;
            //cout << "sum = " << sum << endl;
            ans++;
            //cout << "ans is now" << ans << endl;
        }
        ans--;
        cout << ans << endl;

    }

}
