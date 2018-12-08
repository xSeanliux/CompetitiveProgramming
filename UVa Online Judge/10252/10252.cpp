#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

string s1, s2;

int main(){
    while(getline(cin, s1)){
        getline(cin, s2);
        string ans = "";
        map <char, int> m;
        int l = s1.length();
        for(int i = 0 ; i < l; i++){
            if(!m.count(s1[i])){
                m.insert(pair<char, int>(s1[i], 1));
            } else {
                m[s1[i]]++;
            }
        }
        l = s2.length();
        for(int i = 0 ; i < l; i++){
            if(m.count(s2[i]) && m[s2[i]] > 0){
                m[s2[i]]--;
                ans += s2[i];
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans << endl;
    }
}
