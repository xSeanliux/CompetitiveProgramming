#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int LIM = 5000;
long long int T, n, BIT[LIM + 10], t;

vector<int> arr;

int lowbit(int n){
    return n&-n;
}

int query(int n){
    int res = 0;
    for(int i = n; i > 0; i -= lowbit(i)){
        res += BIT[i];
        //cout << "i = " << i << endl;
    }
    return res;
}

void add(int pos, int val){
    if(pos > LIM) return;
    BIT[pos] += val;
    add(pos + lowbit(pos), val);
}

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        long long int ans = 0;
        for(int i = 0; i <= LIM; i++) BIT[i] = 0;
        for(int i = 0; i < n; i++){
            cin >> t;
            //printf("t = %d\n", t);
            ans += query(t);
            //printf("query res: %d\n", query(t));
            add(t, 1);
        }
        printf("%d\n", ans);
    }
}
