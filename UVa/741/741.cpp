#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

string s;
int n;
bool hasPrinted = false;

int main(){
    while(cin >> s >> n){
        if(s == "END" && !n) return 0;
        string arr[s.length()];
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < s.length(); j++) arr[j] = s[j] + arr[j];
            sort(arr, arr + s.length());
        }
        if(hasPrinted) cout << endl;
        else hasPrinted = true;
        cout << arr[n-1] << endl;
    }
}
