#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int T, N, sum;
string s;
bool b = false;
int mp[30][30];

int getMax(vector<int> v){
    stack<pair<int, int > > stk;
    pair<int, int> p, t;
    int ans = 0;
    for(int i = 0; i < v.size(); i++){
        p = {v[i], i + 1};
        while(!stk.empty() && p.first < stk.top().first){
            t = stk.top(); stk.pop();
            if(stk.empty()){
                ans = max(ans, (int)t.first * i);
            } else {
                ans = max(ans, t.first * (i - stk.top().second));
            }
        }
        stk.push(p);
    }
    while(stk.size()){
        t = stk.top(); stk.pop();
        if(stk.empty()){
            ans = max(ans, (int)t.first * (int)v.size());
        } else {
            ans = max(ans, (int)t.first * ((int)v.size() - stk.top().second));
        }
    }
    return ans;
}

int main(){
    cin >> T;
    while(T--){
        cin >> s;
        N = s.length();
        for(int i = 0; i < N; i++) mp[0][i] = s[i] - '0';
        for(int i = 1; i < N; i++){
            cin >> s;
            for(int j = 0; j < N; j++){
                mp[i][j] = s[j] - '0';
            }
        }
        sum = 0;
        for(int i = 0; i < N; i++){
            sum = 0;
            for(int j = 0; j < N; j++){
                if(!mp[i][j]) sum = 0;
                else sum++;
                mp[i][j] = sum;
            }
        }
        int ans = 0;
        vector<int> current;
        for(int i = 0; i < N; i++){
            current.clear();
            for(int j = 0; j < N; j++){
                current.push_back(mp[j][i]);
            }
            //int k = getMax(current);
            //cout << "For row " <<i  << ", ans = " << k << endl;
            ans = max(ans, getMax(current));
        }
        if(!b) b = true;
        else cout << endl;
        cout << ans << endl;
    }
}
