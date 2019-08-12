#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n;
string s;

int main(){
    cin >> n >> s;
    string news = "";
    for(int i = 0; i < n; i++){
        if(s[i] - '0' < 2) continue;
        if(s[i] == '4'){
            news += "322";
        } else if(s[i] == '6'){
            news += "35";
        } else if(s[i] == '8'){
            news += "7222";
        } else if(s[i] == '9'){
            news += "7332";
        } else {
            news += s[i];
        }
    }
    sort(news.begin(), news.end());
    reverse(news.begin(), news.end());
    cout << news << endl;
}
