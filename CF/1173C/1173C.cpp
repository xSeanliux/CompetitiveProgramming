#include <vector>
#include <iostream>
using namespace std;

int N, t;
const int INF = 2147483647;
vector<int> handfrq, deck, Time;

signed main(){
    cin >> N;
    handfrq.resize(N + 5);
    deck.resize(N + 5);
    Time.resize(N + 5);
    bool sufIsSorted = true;
    int oneIndex = -1;
    for(int i = 0; i < N; i++){
        cin >> t;
        handfrq[t]++;
        Time[t] = 0;
    }
    for(int i = 0; i < N; i++){
        cin >> deck[i];
        Time[deck[i]] = i + 1;
        if(deck[i] == 1) oneIndex = i;
    }
    //cout << "Times: " << endl;
    //for(int i = 1; i <= N; i++) cout << Time[i] << endl;
    //check if suffix is sorted
    int sufTime = INF;
    if(oneIndex != -1){ //is in the array
        for(int i = oneIndex + 1; i < N; i++){
            if(deck[i] - deck[i - 1] != 1){
                sufIsSorted = false;
                break;
            }
        }
        //cout << "suf is sorted: " << sufIsSorted << endl;
        //0 1 2 3 4 5
        //          1
        if(sufIsSorted){ //start trying to take from (n - oneInd) + 1 ~ n
            //Time[i] <= i - ((n - oneInd) + 1)
            //kth round: k + i - ((n - oneInd) + 1) >= time[i]
            bool isGood = true;
            for(int i = N - oneIndex + 1; i <= N; i++){
                if(Time[i] > i - ((N - oneIndex) + 1)){
                    isGood = false;
                    break;
                }
            }
            if(isGood) sufTime = oneIndex;
        }
    }
    int K = 0; //ans for this case is K + n
    //K - i > time[i] so need to + 1
    for(int i = 1; i <= N; i++) K = max(K, Time[i] - i + 1);
    cout << min(sufTime, K + N) << endl;
}
