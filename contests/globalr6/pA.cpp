#include <iostream>
using namespace std;

int N;
string s;

int main(){
    cin >> N;
    while(N--){
        cin >> s;
        int zs = 0, sum = 0, haseven = 0;
        for(char c : s){
            zs += (c == '0');
            sum += (c - '0');
            if((c - '0') % 2 == 0) haseven++;
        }
        if((haseven > 1) && zs > 0 && !(sum % 3)) cout << "red" << endl;
        else cout << "cyan" << endl;
    }

}
