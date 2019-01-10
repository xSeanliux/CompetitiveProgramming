#include <map>
#include <string>
#include <iostream>
using namespace std;

map<string, int> pwds;
int N;
string S;

int main(){
    while(cin >> N >> S){
        pwds.clear();
        int l = S.length();
        for(int i = 0; i <= l - N; i++){
            //cout << S.substr(i, N) << endl;
            string s = S.substr(i, N);
            if(pwds.count(s)){
                pwds[s]++;
            } else {
                pwds.insert(pair<string, int>(s, 1));
            }
        }
        int M = 0;
        string pwd;
        for(map<string, int>::iterator it = pwds.begin(); it != pwds.end(); it++){
            if(it -> second > M){
                M = it -> second;
                pwd = it -> first;
            }
        }
        cout << pwd << endl;
    }



}

