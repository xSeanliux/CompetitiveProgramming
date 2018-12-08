#include <iostream>
#include <string.h>
using namespace std;

string nameA, nameB;
int A, B;
double r;

int sumDigits(int N){
    int ans = 0;
    while(N > 0){
        int k = N % 10;
        ans += k;
        N -= k;
        N /= 10;
    }
    if(ans >= 10){
        return sumDigits(ans);
    } else {
        return ans;
    }
}

int f(string s){
    int ans = 0 ;
    int l = s.length();
    for(int i = 0 ; i < l; i++){
        if('a' <= s[i] && s[i] <= 'z'){
            ans += (s[i] - 'a' + 1);
        } else if('A' <= s[i] && s[i] <= 'Z'){
            ans += (s[i] - 'A' + 1);
        }
    }
    return (sumDigits(ans));

}

int main(){
    while(getline(cin, nameA)){
        getline(cin, nameB);
        //cout << nameA << " " << nameB << endl;
        A = f(nameA);
        B = f(nameB);
        //cout << A << " " << B << endl;
        r = (min(A,B) + 0.0)/max(A,B) * 100;
        printf("%.2f %%\n", r);
    }
}
