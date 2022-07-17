#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxN = 14;

vector<int> vals[10] = {
    {0, 1, 2, 4, 5, 6},
    {2, 5},
    {0, 2, 3, 4, 6},
    {0, 2, 3, 5, 6},
    {1, 2, 3, 5},
    {0, 1, 3, 5, 6},
    {0, 1, 3, 4, 5, 6},
    {1, 0, 2, 5},
    {0, 1, 2, 3, 4, 5, 6},
    {0, 1, 2, 3, 5, 6},
};

int bitval[10], bc[(1 << maxN)], score[(1 << maxN)], inv[1 << 7], ans[maxN + 1][2];
int dp[(1 << maxN)][2][2];

inline int getScore(int mask){
    int d = (mask & ((1 << 7) - 1)), t = (mask >> 7);
    bool isInd = false, isInt = false;
    for(int i = 0; i < 10; i++){
        isInd |= (d == bitval[i]);
        isInt |= (t == bitval[i]);
    }
    if(isInd && isInt) return 10 * inv[t] + inv[d];
    if(!t && isInd) return inv[d];
    return 0;
}

string nums[3] = {
    "._....._.._....._.._.._.._.._.",
    "|.|..|._|._||_||_.|_.|.||_||_|",
    "|_|..||_.._|..|._||_|..||_|._|"
};

void disp(int num){
    vector<int> vec;
    while(num){
        vec.push_back(num % 10);
        num /= 10;
    }
    if(!vec.size()) vec.push_back(0);
    reverse(vec.begin(), vec.end());
    for(int i = 0; i < 3; i++){
        for(int x : vec) cout << nums[i][3 * x] << nums[i][3 * x + 1] << nums[i][3 * x + 2];
        cout << endl;
    }
}

inline void init(){
    for(int i = 0; i < 10; i++){
        for(int x : vals[i]) bitval[i] += (1 << x);
        inv[bitval[i]] = i;
    }
    for(int i = 1; i < (1 << maxN); i++){
        bc[i] = 1 + bc[i ^ (i & -i)];
        score[i] = getScore(i);
    }
}

inline void run(){
    for(int i = 1; i < (1 << maxN); i++){
        for(int j = 0; j < maxN; j++) if((i >> j) & 1){
            int nm = i ^ (1 << j);
            dp[i][0][0] = min(dp[i][0][0], dp[nm][0][1] + score[i]);
            dp[i][0][1] = min(dp[i][0][1], dp[nm][0][0] - score[i]);
            dp[i][1][0] = max(dp[i][1][0], dp[nm][1][1] + score[i]);
            dp[i][1][1] = max(dp[i][0][1], dp[nm][1][0] - score[i]);
        }
        ans[bc[i]][0] = min(ans[bc[i]][0], min(dp[i][0][0], dp[i][0][1]));
        ans[bc[i]][1] = max(ans[bc[i]][1], min(dp[i][1][0], dp[i][1][1]));
    }
    for(int i = 0; i <= maxN; i++){
        //cout << "ans[" << i << "]: " << ans[i][0] << " " << ans[i][1] << endl; 
    }
}



int main(){
    init(); 
    run();
    int N;
    cin >> N;
    disp(-ans[N][0]);    
}

