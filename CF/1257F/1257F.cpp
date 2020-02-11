#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

map<vector<int>, int> mp;
const int maxLog = 30, INF = 1073741824;

vector<int> tophalf, bothalf, topres, botres;
int N, x;

int bitCount(int x){
    int res = 0;
    for(int i = 0; i <= maxLog/2 && (1LL << i) <= x; i++) res += (x & (1LL << i)) > 0;
    return res;
}

int main(){
    cin >> N;
    topres.resize(N);
    botres.resize(N);
    for(int i = 0; i < N; i++){
        cin >> x;
        tophalf.push_back(x >> (maxLog/2));
        bothalf.push_back(x ^ ((x >> (maxLog/2)) << (maxLog/2)) );
    }
    int maxVal, minVal;
    for(int x = 0; x < (1LL << (maxLog/2)); x++){
        minVal = INF;
        for(int i = 0; i < N; i++){
            topres[i] = bitCount(tophalf[i] ^ x);
            minVal = min(minVal, topres[i]);
        }
        for(int i = 0; i < N; i++) topres[i] -= minVal;
        if(!mp.count(topres))
            mp[topres] = x;
    }
    for(int x = 0; x < (1LL << (maxLog/2)); x++){
        minVal = INF, maxVal = -INF;
        for(int i = 0; i < N; i++){
            botres[i] = bitCount(bothalf[i] ^ x);
            minVal = min(minVal, botres[i]);
            maxVal = max(maxVal, botres[i]);
        }
        for(int i = 0; i < N; i++) botres[i] = maxVal - botres[i];
        if(mp.count(botres)){
            cout << ((mp[botres] << (maxLog / 2)) + x) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
