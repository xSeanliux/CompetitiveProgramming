#include <string.h>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

string s;

int main(){
    while(cin >> s){
        int ans = 0, l = s.length();
        set <string> reps;
        for(int i = 0; i < l; i++){
            for(int j = i; j < l; j++){
                string _s = s.substr(i, j - i + 1);
                string __s = _s;
                reverse(__s.begin(), __s.end());
                if(_s == __s && !reps.count(_s)){
                    reps.insert(_s);
                    ans++;
                }
            }
        }
        cout << "The string '" << s << "' contains " << ans << " palindromes." << endl;
    }
}
