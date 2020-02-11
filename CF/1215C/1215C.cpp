#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int n;
string s, t;
vector<int> ab, ba;

int main(){
    cin >> n >> s >> t;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a' && t[i] == 'b') ab.push_back(i);
        if(s[i] == 'b' && t[i] == 'a') ba.push_back(i);
    }
    if(!((ba.size() + ab.size()) % 2)){
        int t = 0;
        if(ba.size() % 2){
            ab.push_back(ba[ba.size() - 1]);
            t++;
        }
        cout << (ab.size() + ba.size()) / 2 + t << endl;
        if(t){
            cout << ba[ba.size() - 1] + 1 << " " << ba[ba.size() - 1] + 1 << endl;
        }
        for(int i = 0; i < ab.size(); i += 2){
            cout << ab[i] + 1 << " " << ab[i + 1] + 1 << endl;
        }
        for(int i = 0; i < ba.size() - t; i += 2){
            cout << ba[i] + 1 << " " << ba[i + 1] + 1 << endl;
        }
    } else {
        cout << -1 << endl;
    }
}
