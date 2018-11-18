#include <iostream>
#include <string.h>
using namespace std;

string s, _t;
int c;
int arr[100 + 5];

int gcd(int a, int b){
    if(b > a) swap(a, b);
    if(a % b == 0) return b;
    else return gcd(b, a%b);
}


int main(){
    cin >> c;
    getline(cin, _t);
    for(int ia = 0; ia < c; ia++){
        getline(cin, s);
        int l = s.length();
        string cS = "";
        int head = 0;
        for(int i = 0; i < l; i++){
            if(s[i] == ' '){
                arr[head] = stoi(cS);
                cS = "";
                head++;
            } else {
                cS += s[i];
                if(i == l-1){
                    arr[head] = stoi(cS);
                    cS = "";
                    head++;
                }
            }
        }
        int mG = 0;
        for(int i = 0; i < head; i++){
            for(int j = i + 1; j < head; j++){
                int k = gcd(arr[i], arr[j]);
                if(k > mG){
                    mG = k;
                }
            }
        }
        printf("%d\n", mG);
    }
}
