#include <iostream>
using namespace std;
int main(){
    int num;
    string ans;
    while(cin >> num){
        ans = (num % 2 == 0) ? "Even" : "Odd";
        cout << ans;
    }
}

