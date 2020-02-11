#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N;
vector<int> a;

int gcd(int a, int b){
    return (!b ? a : gcd(b, a % b));
}

int main(){
    ericxiao;
    cin >> N;
    a.resize(N);
    int m = -1;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        m = max(m, a[i]);
    }
    sort(a.begin(), a.end());
    int g = a[1] - a[0];
    for(int i = 2; i < N; i++){
        g = gcd(a[i] - a[i - 1], g);
    }
    long long int cnt = 0;
    for(int i = 0; i < N; i++){
        cnt += (m - a[i]) / g;
        //cout << (m - a[i]) / g << endl;
    }
    cout << cnt << " " << g << endl;
}

