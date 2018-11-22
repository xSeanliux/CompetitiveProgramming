#include <iostream>
#include <math.h>

using namespace std;

string s;

long long int toDec(string s){
    long long int res = 0;
    int l = s.length();
    int deg = l - 1;
    for(int i = 0 ; i < l; i++){
        if(s[i] != '0'){
            res += (s[i] - '0') * (pow(2, l-i) - 1);
            //cout << s[i] << "*" <<  pow(-2, l-i) << endl;
        }

    }
    return res;
}


int main(){
    while(cin >> s){
        if(s == "0") return 0;
        else
            printf("%lld\n", toDec(s));
    }
}
