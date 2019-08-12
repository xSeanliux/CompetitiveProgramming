#include <iostream>
#include <algorithm>
#include <math.h>
#define MAXN 100000
using namespace std;
//urgh this problem is really annoying

int T;

int getDigLen(int n){
    if(n < 10) return 1;
    else if(n < 100) return 2;
    else if(n < 1000) return 3;
    else if(n < 10000) return 4;
    else if(n < 100000) return 5;
    else if(n < 1000000) return 6;
}

int main(){
    unsigned long long int len[MAXN + 1], sup[MAXN + 1], N;
    len[1] = 1, sup[1] = 1;
    for(int i = 2; i <= MAXN; i++){
        sup[i] = sup[i-1] + getDigLen(i);
        len[i] = len[i-1] + sup[i];
        len[i-1] -= sup[i-1] - 1;
    }
    cin >> T;
    while(T--){
        cin >> N;
        int ind = upper_bound(len + 1, len + MAXN + 1, N) - len - 1;
        N -= len[ind];

        //from 1 to ind, get Nth in the string
        long long int digs[20], cp = 1;
        digs[1] = 0; //starting, e.g. things with one digits start at 0, two digits start at index 9...
        digs[0] = -100;
        for(long long int i = 2; i < 20; i++){ //get how many digits
            digs[i] = digs[i-1] + 9*(i-1)*cp;
            cp *= 10;
            //printf("digs[%llu] = %llu\n", i, digs[i]);
        }
        int digits = upper_bound(digs + 1, digs + 20, N) - digs - 1;
        //printf("%d digits starting at %lld\n", digits, digs[digits]);
        N -= digs[digits];
        int getNum = N/digits + pow(10, digits-1); //get the actual number
        int nthNum = N % digits; //get the character out
        cout << to_string(getNum)[nthNum] << endl;
    }
}
