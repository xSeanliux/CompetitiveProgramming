#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<int> id, cnt1, cnt2, cnt3, maxval;
int n, x, p, m, s;

int main(){
    ericxiao;
    cin >> p >> m >> s;
    n = p + m + s;
    id.resize(n + 2);
    cnt1.resize(n + 2);
    cnt2.resize(n + 2);
    cnt3.resize(n + 2);
    maxval.resize(n + 2);
    for(int i = 0; i < p; i++){
        cin >> x;
        id[x] = 1;
        cnt1[x]++;
    }
    for(int i = 0; i < m; i++){
        cin >> x;
        id[x] = 2;
        cnt2[x]++;
    }
    for(int i = 0; i < s; i++){
        cin >> x;
        id[x] = 3;
        cnt3[x]++;
    }

    for(int i = 1; i <= n + 1; i++){
        cnt1[i] += cnt1[i - 1];
        cnt2[i] += cnt2[i - 1];
        cnt3[n + 1 - i] += cnt3[n + 2 - i];
    }
    /*
    for(int i = 1; i <= n; i++){
        cout << id[i] << " ";
    }
    cout << endl;

    for(int i = 0; i <= n + 1; i++){
        cout << cnt1[i] << " ";
    }
    cout << endl;

    for(int i = 0; i <= n + 1; i++){
        cout << cnt2[i] << " ";
    }
    cout << endl;

    for(int i = 0; i <= n + 1; i++){
        cout << cnt3[i] << " ";
    }
    cout << endl;
    */
    for(int i = 1; i <= n + 1; i++){
        maxval[i] = cnt2[i - 1] + cnt3[i];
        //cout << maxval[i] << " ";
    }
    //cout << endl;
    for(int i = n; i >= 1; i--){
        maxval[i] = max(maxval[i], maxval[i + 1]);
    }
    int mv = -1;
    for(int i = 1; i <= n + 1; i++){
        mv = max(mv, cnt1[i - 1] + maxval[i] - cnt2[i - 1]);
    }
    cout << n - mv << endl;

}
