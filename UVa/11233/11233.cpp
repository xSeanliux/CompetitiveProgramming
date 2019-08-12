#include <iostream>
#include <string.h>
#include <map>
using namespace std;

map<string, string> mp;
int N, M;
string a, b;

bool isVowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}



int main(){
    scanf("%d%d", &N, &M);
    while(N--){
        cin >> a >> b;
        mp.insert({a, b});
    }
    while(M--){
        cin >> a;
        if(mp.count(a)) cout << mp[a] << endl;
        else if(a.length() > 1 && !isVowel(a[a.length() - 2]) && a[a.length() - 1] == 'y'){
            cout << a.substr(0, a.length() - 1) << "ies" << endl;
        } else if(a[a.length() - 1] == 'o' || a[a.length() - 1] == 's' || a[a.length() - 1] == 'x' || (a.length() > 1 && (a.substr(a.length() - 2, 2) == "ch" || a.substr(a.length() - 2, 2) == "sh" ||a.substr(a.length() - 2, 2) == "es"))){
            cout << a << "es" << endl;
        } else {
            cout << a << "s" << endl;
        }
    }
}
