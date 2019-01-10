#include <iostream>
#include <string.h>
#include <stack>
#include <map>
#define INF 2147483647
using namespace std;

int process(string s){ //return 0 for perfect matching, pos num for no of (, neg num for no of ), and inf for not good pair
    stack<char> sta;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            sta.push('(');
        } else {
            if(!sta.empty() && sta.top() == '('){
                sta.pop();
            } else {
                sta.push(')');
            }
        }
    }
    if(sta.empty()) return 0;
    char c = sta.top();
    int cnt = 0;
    while(!sta.empty()){
        if(sta.top() == c){
            cnt++;
            sta.pop();
        } else {
            return INF;
        }
    }
    if(c == ')') cnt = -cnt;
    return cnt;

}

string s;
int N;
map <int, int> vals;

int main(){
    int ans = 0;
    cin >> N;
    while(N--){
        cin >> s;
        int k = process(s);
        if(k != INF){
            if(vals.count(-k)){
                vals[-k]--;
                if(!vals[-k]) vals.erase(-k);
                ans++;
            } else {
                if(vals.count(k)){
                    vals[k]++;
                } else {
                    vals.insert(pair<int, int>(k, 1));
                }
            }
        }
    }
            cout << ans << endl;

}
