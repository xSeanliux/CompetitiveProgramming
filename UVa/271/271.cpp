#include <iostream>
#include <string.h>
using namespace std;

bool isGood = true, visited[300];
string s;
int L;

int run(int ite){
    //cout << "Run(" << ite << ")" << endl;
    if(ite >= L){
        isGood = false;
        return ite;
    }
    visited[ite] = true;
    //cout << "Running run(" << s[ite] << ")" << endl;
    if(s[ite] == 'N'){
        int res = run(ite + 1);
        if(res >= L){
            isGood = false;
        }
        //cout << "Ends at " << res << endl;
        return res;
    } else if(s[ite] <= 'z' && s[ite] >= 'p'){
        //cout << "Ends at" << ite << endl;
        return ite;
    } else {
        int res = run(ite + 1);
        if(res >= L){
            isGood = false;
            //cout << "Ends at " << res << endl;
            return res;
        }
        int res2 = run(res + 1);
        //cout << "Ends at " << res2 << endl;
        if(res >= L){
            isGood = false;
            return res2;
        }

        return res2;
    }
}

int main(){
    while(cin >> s){
        L = s.length();
        int res = run(0);
        isGood = true;
        if(res != L-1 || !isGood) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
