#include <iostream>
#include <map>
#include <vector>
#include <string.h>
using namespace std;

int t, n;
string s;

int main(){
    cin >> t;
    while(t--){
        map<string, int> mp;
        vector<string> vec;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s;
            mp[s]++;
            vec.push_back(s);
        }
        int res = 0;
        for(string &s : vec){
            if(mp[s] > 1){
                mp[s]--;
                res++;
                string ori = s;
                bool isDone = false;
                for(int i = 0; i < 4 && !isDone; i++){
                    for(int j = '0'; j <= '9'; j++){
                        s[i] = j;
                        if(!mp.count(s)){
                            isDone = true;
                            mp[s]++;
                            break;
                        } else {
                            s = ori;
                        }
                    }
                }
            }
        }

        cout << res << endl;
        for(string s : vec) cout << s << endl;
    }
}
