#include <iostream>
#include <utility>
#include <set>
#include <queue>
#include <string.h>
#define pii pair<int,int>
using namespace std;

string s;

set<string> st;
set<pii> hasbeen;
queue<pii> que;
string last, now;
int main(){
    cin >> s;
    int l = s.length();
    que.push({l - 1, 0});
    pii p;
    while(que.size()){
        p = que.front();
        //cout << p.first << ", " << p.second << endl;
        que.pop();
        last = "";
        for(int i = p.first + 1; i <= p.first + p.second; i++){
            last += s[i];
        }
        if(p.first >= 7){
            now = s[p.first - 1];
            now += s[p.first];
            if(last != now){
                pii newp = {p.first - 2, 2};
                st.insert(now);
                if(!hasbeen.count(newp)){
                    que.push(newp);
                    hasbeen.insert(newp);
                }
            }
            now = s[p.first - 2] + now;
            if(last != now){
                pii newp = {p.first - 3, 3};
                st.insert(now);
                if(!hasbeen.count(newp)){
                    que.push(newp);
                    hasbeen.insert(newp);
                }
            }
        } else if(p.first == 6){
            now = s[p.first - 1];
            now += s[p.first];
            if(last != now){
                pii newp = {p.first - 2, 2};
                st.insert(now);
                if(!hasbeen.count(newp)){
                    que.push(newp);
                    hasbeen.insert(newp);
                }
            }
        }
    }
    cout << st.size() << endl;
    for(string str : st){
        cout << str << endl;
    }
}
