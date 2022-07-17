#include <iostream>
#include <queue>
#include <utility>
#include <iomanip>
#include <math.h>
#define pdi pair<double,int>
#define F first
#define S second
#define double long double
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 326;
const double eps = 1e-10;

priority_queue<pdi, vector<pdi>> pq;

int N, X;
double len[maxN], sl[maxN], ans, newsl[maxN];

double can(double e, int &need){
    need = 0;
    for(int i = 0; i < N; i++) newsl[i] = sl[i];
    double ans = 0;
    //cout << "e = " << e << endl;
    for(int i = 0; i < N; i++){
        if(len[i] <= e * sl[i] * (sl[i] + 1) - eps){
            ans += len[i] / sl[i];
            continue;
        }
        int t = (int)floor((e * (-2 * sl[i] - 1) + sqrt(e * e + 4 * e * len[i])) / 2 / e - eps);
        //cout << "t = " << t << endl;
        for(double k = max(1LL, (int)t - 3); ; k++){
            if(len[i] <= e * (sl[i] + k + 1) * (sl[i] + k) - eps){
                ans += len[i] / (sl[i] + k);
                newsl[i] += k;
                need += round(k);
                //cout << "K = " << k << endl;
                //cout << "changing " << len[i] << "/" << sl[i] << " to " << len[i] << "/" << sl[i] + k << endl;
                break;
            }
        }
        //cout << "changing " << len[i] << "/" << sl[i] << " to " << len[i] << "/" << sl[i] + t << endl;
        //ans += len[i] / (sl[i] + t);
        //need += t;
        if(need - eps > X) return -1;
    }
    if(need > X) return -1;
    //cout << "require " << need << endl; 
    return ans;
}

signed main() {
    /*
    double A[5] = {2, 5, 3, 2, 4}, B[5] = {5, 4, 3, 3, 3};
    for(int i = 0; i < 5; i++) cout << A[i] / B[i] / (B[i] + 1)<< endl;
    */
    ericxiao;
    cin >> N >> X;
    for(int i = 0; i < N; i++) cin >> len[i];
    for(int i = 0; i < N; i++){
        cin >> sl[i];
    }
    double l = 0, r = 1e5, m;
    int need;
    while(r - l > eps){
        m = (l + r) / 2;
        if(can(m, need) >= eps) r = m;
        else l = m;
    }
    double ans = can(r, need);
    X -= need;
    for(int i = 0; i < N; i++){
        pq.push({len[i] / (newsl[i]) - len[i] / (newsl[i] + 1), i});
    }
    while(X--){
       auto [del, ind] = pq.top();
       pq.pop();
       ans -= del;
       newsl[ind]++;
       pq.push({len[ind] / (newsl[ind]) - len[ind] / (newsl[ind] + 1), ind});
    }
    cout << fixed << setprecision(10) << ans << endl;
}
