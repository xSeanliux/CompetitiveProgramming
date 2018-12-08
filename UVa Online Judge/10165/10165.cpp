#include <iostream>
#include <string>
using namespace std;

int n;
string s;

int main(){
    while(cin >> n){
        if(!n) return 0;
        getline(cin, s);
        if(n % 2 == 0){
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}
