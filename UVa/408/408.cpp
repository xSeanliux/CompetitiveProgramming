#include <iostream>
#include <map>
using namespace std;

int A, B;
bool hasPrnt = false;

int gcd(int a, int b){
    int t;
    while(b){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(){
    map<pair<int, int>, bool> mp;
    while(cin >> A >> B){
        printf("%10d%10d    ", A, B);
        if(A > B) swap(A, B);
        if(!mp.count(pair<int, int>(A, B))){
            mp.insert(pair<pair<int, int>, bool>(pair<int, int>(A, B), (gcd(A, B) == 1)));
        }
        if(mp[pair<int, int>(A, B)]){
            printf("Good Choice");
        } else {
            printf("Bad Choice");
        }
        printf("\n\n");
    }
}
