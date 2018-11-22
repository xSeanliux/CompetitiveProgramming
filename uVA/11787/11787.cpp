#include <iostream>
#include <math.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
map <char, int> cp;
int numOfEach[10];
int N;
string s;

bool charCmp1(const char &a, const char &b){
    return cp[a] > cp[b];
}

bool charCmp2(const char &a, const char &b){
    return cp[a] < cp[b];
}

int main(){
    cp.insert(pair<char, int>('B', 0));
    cp.insert(pair<char, int>('U', 1));
    cp.insert(pair<char, int>('S', 2));
    cp.insert(pair<char, int>('P', 3));
    cp.insert(pair<char, int>('F', 4));
    cp.insert(pair<char, int>('T', 5));
    cp.insert(pair<char, int>('M', 6));
    cin >> N;
    while(N--){
        cin >> s;
        string newS1 = s, newS2 = s;
        sort(newS1.begin(), newS1.end(), charCmp1);
        sort(newS2.begin(), newS2.end(), charCmp2);
        if(newS1 != s && newS2 != s){
            cout << "error" << endl;
            continue;
        }
        int l = s.length();
        bool canDo = true;
        for(int i = 0; i < 7; i++)
            numOfEach[i] = 0;
        for(int i = 0; i < l && canDo; i++){
            if(cp.count(s[i])){
                //cout << "numofeach[" << cp[s[i]] << "]++" << endl;
                numOfEach[cp[s[i]]]++;
            } else {
                cout << "error" << endl;
                canDo = false;
                break;
            }
        }
        if(canDo){
            int ans = 0;
            for(int i = 0 ; i < 7; i++){
                if(numOfEach[i] < 10){
                    ans += numOfEach[i] * pow(10, i);
                } else {
                    cout << "error" << endl;
                    canDo = false;
                    break;
                }
            }
            if(canDo){
                cout << ans << endl;
            }
        }

    }
}
