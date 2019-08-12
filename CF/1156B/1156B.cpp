#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
using namespace std;

int T;
string s;
vector<char> v;
map<char, int> mp;

int main(){
    cin >> T;
    while(T--){
        cin >> s;
        v.clear();
        mp = map<char, int>();
        sort(s.begin(), s.end());
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            int cnt = 0;
            while(s[i] == c){
                cnt++;
                i++;
            }
            v.push_back(c);
            mp.insert({c, cnt});
            i--;
        }
        vector<char> odd, even;
        for(int i = 0; i < v.size(); i++){
            (i % 2 ? odd : even).push_back(v[i]);
        }
        string ans1 = "", ans2 = "";
        for(char c : even){
            for(int i = 0; i < mp[c]; i++){
                ans1 += c;
            }
        }
        for(char c : odd){
            for(int i = 0; i < mp[c]; i++){
                ans1 += c;
            }
        }
        for(char c : odd){
            for(int i = 0; i < mp[c]; i++){
                ans2 += c;
            }
        }
        for(char c : even){
            for(int i = 0; i < mp[c]; i++){
                ans2 += c;
            }
        }
        bool canDo1 = true, canDo2 = true;
        for(int i = 1; i < s.length(); i++){
            if(ans1[i] - ans1[i-1] == -1 || ans1[i] - ans1[i-1] == 1){
                //cout << "No answer" << endl;
                canDo1 = false;
            }
            if(ans2[i] - ans2[i-1] == -1 || ans2[i] - ans2[i-1] == 1){
                //cout << "No answer" << endl;
                canDo2 = false;
            }
            if(!canDo1 && !canDo2){
                cout << "No answer" << endl;
                break;
            }
        }

        if(canDo1){
            cout << ans1 << endl;
        } else if(canDo2){
            cout << ans2 << endl;
        }
    }
}
