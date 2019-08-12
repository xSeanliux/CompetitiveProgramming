#include <iostream>
#include <vector>
using namespace std;

struct Obj{
    int val, longLen, ways, from;
    Obj(int v = 0): val(v), longLen(1), from(-1), ways(1){}
};

vector<Obj> v, rev;
const int MOD = 1e9 + 7;
int N, x;

int main(){
    cin >> N;
    ios_base::sync_with_stdio(0); cin.tie(0);
    v.resize(N);
    rev.resize(N);
    for(int i = 0; i < N; i++){
        cin >> x;
        v[i] = Obj(x);
        rev[N - 1 - i] = Obj(-x);
    }
    //get the number of ways in O(N^2)
    int mL = 0, ansWays = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            //get the longest that is rightmost and less than x
            //sum: the longest and less than x
            if(rev[i].val >= rev[j].val){
                if(rev[i].longLen == rev[j].longLen + 1){
                    rev[i].ways += rev[j].ways;
                    rev[i].ways %= MOD;
                    rev[i].from = j;
                }
                else if (rev[i].longLen < rev[j].longLen + 1){
                    rev[i].ways = rev[j].ways % MOD;
                    rev[i].longLen = rev[j].longLen + 1;
                    rev[i].from = j;
                }
            }
        }
        //cout << "v[" << i << "].longlen = " << v[i].longLen << endl;
        mL = max(mL, rev[i].longLen);
    }
    //cout << "mL = " << mL << endl;
    cout << mL << endl;
    for(int i = 0; i < N; i++) ansWays = (ansWays + (mL == rev[i].longLen) * rev[i].ways) % MOD;
    cout << ansWays << endl;

    //get lexicographically least one from rev
    vector<int> ans;
    bool isOk = false;
    for(int i = N - 1; i >= 0; i--){
        if(isOk) break;
        if(rev[i].longLen == mL){ //awesome
            int k = i;
            while(k != -1){
                ans.push_back(N - k);
                k = rev[k].from;
            }
            isOk = true;
        }
    }
    cout << ans[0];
    for(int i = 1; i < ans.size(); i++) cout << " " << ans[i];
    cout << endl;

}
