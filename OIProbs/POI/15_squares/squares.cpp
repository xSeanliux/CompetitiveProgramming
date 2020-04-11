#pragma GCC optimize ("O3")
#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e6 + 10, maxC = 200;

int k[maxN], bit[maxN], pre[maxN], nixu[maxN];
vector<int> pos;

void add(int p){
    for(; p < maxC; p += (p & -p)) bit[p]++;
}

int query(int p){
    int r = 0 ;
    for(; p; p -= (p & -p)) r += bit[p];
    return r;
}

int main(){
    k[0] = 0;
    for(int i = 1; i < maxN; i++){
        k[i] = maxC - 1;
        for(int t = 1; t * t <= i; t++){
            if(k[i - t * t] < t){
                k[i] = t;
                break;
            }
        }
    }
    int curMin = k[maxN - 1];
    for(int i = maxN - 1; i; i--){
        if(k[i] > curMin){
            pre[i] = 1;
        } else{
            pos.push_back(i);
        }
        curMin = min(curMin, k[i]);
    }
    cout << pos.size() << endl;
    /*
    cout << "int k[1000010] = {";
    for(int i = 0; i < maxN; i++) cout << k[i] << ",}"[i == maxN - 1];
    cout << ";";
    cout << "int pre[1000010] = {";
    for(int i = 0; i < maxN; i++) cout << pre[i] << ",}"[i == maxN - 1];
    cout << ";";
    */
    int N;
    cin >> N;
    if(k[N] == maxC - 1) cout << "-";
    else cout << k[N];
    cout << " ";
    cout << pre[N] << endl;
}
