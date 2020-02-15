#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define int long long int
using namespace std;

int vl, vr, pl, pr, k, INF = 1e9 + 10;
vector<int> lucky;

void init(){
    int r;
    lucky.push_back(0);
    lucky.push_back(INF);
    for(int l = 1; l < 10; l++){
        for(int i = 0; i < (1LL << l); i++){
            r = 0;
            for(int j = 0; j < l; j++){
                r = r * 10 + 4 + (1 & (i >> j)) * 3;
            }
            lucky.push_back(r);
        }
    }
    sort(lucky.begin(), lucky.end());
    //for(int x : lucky) cout << x << endl;
}

int intersect(int al, int ar, int bl, int br){
    return max(0LL, min(ar, br) - max(al, bl) + 1);
}

signed main(){
    cout << fixed << setprecision(10);
    init();
    cin >> vl >> vr >> pl >> pr >> k;
    int num = 0, sgn = 1, l, r;
    if(k == 1){
        for(int i = 1; i < lucky.size() - k; i++){ //from lucky[i] to
            l = lucky[i], r = lucky[i + k - 1];
            //if(r > max(vr, pr)) break;
            //num += sgn * max(0LL, )
            //cout << "First seg: " << lucky[i - 1] << ", " << lucky[i] << endl;
            //cout << "Second seg: " << lucky[i + k - 1] << ", " << lucky[i + k] << endl;
            num += intersect(lucky[i - 1] + 1, lucky[i], vl, vr) * intersect(lucky[i + k - 1], lucky[i + k] - 1, pl, pr);
            num += intersect(lucky[i - 1] + 1, lucky[i], pl, pr) * intersect(lucky[i + k - 1], lucky[i + k] - 1, vl, vr);
            num -= intersect(lucky[i], lucky[i], pl, pr) * intersect(lucky[i + k - 1], lucky[i + k - 1], vl, vr);
        }
        cout << 1.0 * num / (vr - vl + 1) / (pr - pl + 1) << endl;
        return 0;
    }

    for(int i = 1; i < lucky.size() - k; i++){ //from lucky[i] to
        l = lucky[i], r = lucky[i + k - 1];
        //if(r > max(vr, pr)) break;
        //num += sgn * max(0LL, )
        //cout << "First seg: " << lucky[i - 1] << ", " << lucky[i] << endl;
        //cout << "Second seg: " << lucky[i + k - 1] << ", " << lucky[i + k] << endl;
        num += intersect(lucky[i - 1] + 1, lucky[i], vl, vr) * intersect(lucky[i + k - 1], lucky[i + k] - 1, pl, pr);
        num += intersect(lucky[i - 1] + 1, lucky[i], pl, pr) * intersect(lucky[i + k - 1], lucky[i + k] - 1, vl, vr);
    }
    //cout << "num = " << num << endl;
    cout << 1.0 * num / (vr - vl + 1) / (pr - pl + 1) << endl;
}
