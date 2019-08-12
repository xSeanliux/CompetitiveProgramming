#include <iostream>
#define lli unsigned long long int
using namespace std;

lli n, q, a, b, c, d;

lli arr[(lli)2e5 + 5], bit[(lli)2e5 + 5];

lli lowbit(lli x){
    return x & -x;
}

lli query(lli pos){
    if(!pos) return 0;
    return bit[pos] + query(pos - lowbit(pos));
}

void update(lli pos, lli toAdd){
    if(pos > n) return;
    bit[pos] += toAdd;
    update(pos + lowbit(pos), toAdd);
}


int main(){
    cin >> n >> q;
    lli x;
    for(int i = 1; i <= n; i++) bit[i] = 0;
    for(int i = 1; i <= n; i++){ //build tree
        cin >> arr[i];
        update(i, arr[i]);
    }
    while(q--){
        cin >> a >> b >> c;
        if(a == 1){
            cin >> d;
            for(int i = b; i <= c; i++) {
                int newVal = arr[i] ^ d;
                update(i, newVal - arr[i]);
                arr[i] = newVal;
            }
        } else {
            lli res = 0;
            for(int i = b; i <= c; i++) res += arr[i];
            printf("%llu\n", query(c) - query(b - 1));
        }
    }
}

