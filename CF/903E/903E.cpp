#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int N, K;
bool existDupe = false;
vector<string> v, sor;
vector<int> D;


int dist(string a, string b){
    int res = 0;
    for(int i = 0; i < N; i++) res += (a[i] != b[i]);
    return res;
}

bool isValid(int i, int j){
    int d, newD;
    for(int k = 1; k < K; k++){
        //d' = d + deltaD
        d = D[k];
        newD = d + (v[k][i] == v[0][i]) + (v[k][j] == v[0][j]) - (v[k][i] == v[0][j]) - (v[k][j] == v[0][i]);
        if(!(newD == 2 || (newD == 0 && existDupe))) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> N;
    v.resize(K);
    D.resize(K);
    sor.resize(K);
    for(int i = 0; i < K; i++){
        cin >> v[i];
        sor[i] = v[i];
        sort(sor[i].begin(), sor[i].end());
        if(sor[i] != sor[0]){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 0; i < N - 1; i++) if(sor[0][i] == sor[0][i + 1]) existDupe = true;
    string mother;
    for(int i = 1; i < K; i++) D[i] = dist(v[0], v[i]);
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(isValid(i, j)){
                //cout << i << ", " << j << endl;
                swap(v[0][i], v[0][j]);
                cout << v[0] << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}
