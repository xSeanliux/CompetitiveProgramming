#include <iostream>
#include <string.h>
using namespace std;

string str;
int p;
int main(){
    while(cin >> p){
        if(!p) return 0;
        cin >> str;
        int l = str.length();
        string ans = "";
        p = l/p;
        int currentIndex = 0;
        while(currentIndex < l){
            for(int i = currentIndex + p - 1; i >= currentIndex; i--){
                ans += str[i];
            }
            currentIndex = min(l, currentIndex + p);

        }
        cout << ans << endl;
    }
}
