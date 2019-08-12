#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int det(vector<vector<int> > v, int sz){
    if(sz == 1) return v[0][0];
    int k = 1, ans = 0;
    vector<vector<int> > _v;
    for(int i = 0; i < sz; i++){
        _v.clear();
        _v.resize(sz - 1);
        for(int j = 1; j < sz; j++){
            for(int k = 0; k < sz; k++){
                if(i == k) continue;
                _v[j - 1].push_back(v[j][k]);
            }
        }
        ans += k * det(_v, sz - 1) * v[0][i];
        k *= -1;
    }
    return ans;
}

int gcd(int a, int b){
    return (!b ? a : gcd(b, a % b));
}

int N;
vector<vector<int> > coe, cur;
vector<int> res;
int main(){
    cin >> N;
    coe.resize(N);
    res.resize(N);
    for(int i = 0; i < N; i++){
        coe[i].resize(N);
        for(int j = 0; j < N; j++){
            cin >> coe[i][j];
        }
        cin >> res[i];
    }
    int D = det(coe, N);
    if(!D){
        cout << "NO SOLUTION!" << endl;
        return 0;
    }
    //cout << "Det = " << D << endl;
    cur.resize(N);
    for(int i = 0; i < N; i++){
        cur.clear();
        cur.resize(N);
        for(int j = 0; j < N; j++){
            cur[j].resize(N);
            for(int k = 0; k < N; k++){
                cur[j][k] = (k == i ? res[j] : coe[j][k]);
            }
        }
        int res = det(cur, N);
        int g = gcd(res, D);
        cout << (char)((i) % 26 + 'a') << " = " <<  res << "/" << D;
        if(!(res % D)){
            cout << " = " << res/D << endl;
        } else {
            if(res * D < 0){
                cout << " = -" << abs(res/g) << "/" << abs(D/g) << endl;
            } else {
                cout << " = " << res/g << "/" << D/g << endl;
            }
        }
    }
}
