#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6;
int pos[N + 5], neg[N + 5];

//unordered_map<int, long long int> pos, neg;

int n, x;

int main(){
    cin >> n;
    unsigned long long int ans = 0;
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        cin >> pos[i];
        neg[i] = pos[i] - i;
        pos[i] += i;
    }
    sort(pos + 1, pos + 1 + n);
    sort(neg + 1, neg + 1 + n);
    unsigned long long int k = 1;
    for(int i = 1; i < n; i++){
        while(pos[i] == pos[i+1]){
            k++;
            i++;
        }
        ans += k*(k-1);
        //cout << k*(k-1) << endl;
        k = 1;
    }
    k = 1;
    for(int i = 1; i < n; i++){
        while(neg[i] == neg[i+1] && i < n){
            k++;
            i++;
        }
        ans += k*(k-1);
        //cout << k << endl;
        k = 1;
    }
    cout << ans << endl;
}
