#include <iostream>
#include <string.h>
#include <vector>
#include <set>
using namespace std;
string a, b;
bool f = false;
int main(){
    while(cin >> a >> b){
        set<string> S, T;
        int l = a.length(), mL = 0;
        for(int i = 0; i < l; i++){
            for(int j = 1; j <= l-i; j++){
                S.insert(a.substr(i, j));
            }
        }
        l = b.length();
        for(int i = 0; i < l; i++){
            for(int j = 1; j <= l-i; j++){
                if(S.count(b.substr(i, j))){
                    mL = max(mL, j);
                    T.insert(b.substr(i, j));
                }
            }
        }
        int pc = 0;
        if(!f) f = true;
        else cout << endl;
        for(set<string>::iterator i = T.begin(); i != T.end(); i++){
            if(i->length() == mL){
                cout << *i << endl;
                pc++;
            }
        }
        if(!pc) cout << "No common sequence." << endl;
    }
}



/*below is multiple LCS lol
string A, B;
int dp[305][305], len, lA, lB;
char ans[305], chs[] = {'a', 'c', 'g', 't'};
bool hp = true;

int lcs(int ai, int bi){//the length of lcs from A[i...lA-1], B[j...lB-1]
    int &res = dp[ai][bi];
    if(ai == lA || bi == lB) return res = 0;
    if(res != -1) return res;
    res = 0;
    if(A[ai] == B[bi]){
        res = 1 + lcs(ai + 1, bi + 1);
    } else {
        res = max(lcs(ai, bi + 1), lcs(ai+1, bi));
    }
    return res;
}


void get(int indA, int indB, int currentlcs){
    //cout << "Running f(" << indA << ", " << indB << ", " << currentlcs << ")" << endl;
    if(currentlcs == len){
        for(int i = 0; i < len; i++){
            cout << ans[i];
        }
        cout << endl;
        return;
    }
    if(indA == lA || indB == lB) return;
    bool done = false;
    for(int k = 0; k <= 3; k++){
        done = false;
        char ch = chs[k];
        for(int i = indA; i < lA; i++){
            if(ch == A[i]){
                for(int j = indB; j < lB; j++){
                    if(ch == B[j] && lcs(i, j) == len - currentlcs){
                        ans[currentlcs] = ch;
                        get(i + 1, j + 1, currentlcs + 1);
                        done = true;
                        break;
                    }
                }
            }
            if(done) break;
        }

    }
}


int main(){
    while(cin >> A >> B){
        lA = A.length(),lB = B.length();
        for(int i = 0; i < lA; i++){
            for(int j = 0; j < lB; j++){
                dp[i][j] = -1;
            }
        }
        len = lcs(0, 0);
        //cout << len << endl;
        if(hp) hp = false;
        else cout << endl;
        get(0, 0, 0);
    }
}
*/
