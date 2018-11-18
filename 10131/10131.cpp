#include <iostream>
#include <algorithm>
using namespace std;

struct Ele{
    int iq, wei, nth, ind;
} eles[1004];


int w, iq, head = 0;

bool eleCmp(const Ele a, const Ele b){
    if(a.iq == b.iq){
        return a.wei > b.wei;
    }
    return a.iq > b.iq;
}

int main(){
    while(cin >> w >> iq){
        eles[head].wei = w;
        eles[head].iq = iq;
        eles[head].nth = head;
        head++;
    }
    sort(eles, eles + head, eleCmp);
    /*
    for(int i = 0 ; i < head; i++){
        cout << eles[i].wei << " " << eles[i].iq << endl;
    }
    */
    int dp[1005];
    fill(dp, dp + head, 2147483647);
    for(int i = 0; i < head; i++){
        int k = lower_bound(dp, dp + head, eles[i].wei) - dp;
        eles[i].ind = k;
        *lower_bound(dp, dp + head, eles[i].wei) = eles[i].wei;
    }
    int maxLen = lower_bound(dp, dp + head, 2147483647) - dp;
    cout << maxLen << endl;
    int current = maxLen-1;
    int ansarr[maxLen];
    for(int i = head - 1; i >= 0; i--){
        if(eles[i].ind == current){
            ansarr[current] = eles[i].nth + 1;
            current--;
        }
    }
    for(int i = 0 ; i < maxLen; i++){
        cout << ansarr[i] << endl;
    }
    //sort elephants such that iqs are decreasing, and if same, then weights decreasing
    //then LIS on weight
}
