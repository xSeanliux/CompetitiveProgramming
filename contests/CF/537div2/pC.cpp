#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

unsigned long long int n, k, A, B, arr[(int)1e5 + 10];

int getnthblock(int n, int depth){ //depth 0 is starting depth, and n starts from 1
    return n/pow(2, depth);
}


unsigned long long int getAns(long long int l, long long int r){
    unsigned long long int mid = (l + r)/2; //count how many there are in l ~ mid and mid + 1 ~ r
    unsigned long long int lcount = upper_bound(arr, arr + k, mid) - lower_bound(arr, arr + k, l);
    unsigned long long int rcount = upper_bound(arr, arr + k, r) - lower_bound(arr, arr + k, mid + 1);
    //cout << lcount << " between " << l << " and " << mid << ", " << rcount << " between " << mid + 1 << " and " << r << endl;
    unsigned long long int total = lcount + rcount;
    if(l == r){
        if(total) return total * B;
        else return A;
    }
    if(!total) return A;
    else if(lcount > 0 && rcount > 0){
        return min((unsigned long long)B * (r - l + 1) * total, (unsigned long long int)(getAns(l, mid) + getAns(mid + 1, r)));
    } else if(lcount > 0){
        return min((unsigned long long)B * (r - l + 1) * total, (unsigned long long int)(getAns(l, mid) + A));
    } else {
        return min((unsigned long long)B * (r - l + 1) * total, (unsigned long long int)(getAns(mid  + 1, r) + A));
    }
}


int main(){
    cin >> n >> k >> A >> B;
    for(int i = 1; i <= k; i++) cin >> arr[i];
    sort(arr, arr + k);
    printf("%llu\n", getAns((unsigned long long int)1, (unsigned long long int)pow(2, n)));
}
