#include <iostream>
using namespace std;

int T, N;

long long int modexp(int b, int e, int m){
    if(e == 1) return b % m;
    long long int res = modexp(b, e/2, m);
    res = res * res % m;
    if(e % 2) res = res * b % m;
    return res;
}

bool isPrime(long long int k){
    if(k == 1) return false;
    if(!(k % 2)) return (k == 2);
    int toTest[] = {2, 3, 5, 7, 11, 13, 17};
    int d = k-1, r = 0;
    while(!(d % 2)){
        r++;
        d /= 2;
    }
    for(int i = 0; i < 6 && toTest[i] != k; i++){
        long long int x = modexp(toTest[i], d, k);
        if(x == 1 || x == k-1) continue;
        bool flag = false;
        for(int j = 1; j < r; j++){
            x = (x * x) % k;
            if(x == k-1){
                flag = true;
                break;
            }
        }
        if(!flag) return false;
    }
    return true; //get if prime how do i
}

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        long long int arr[N + 1], sum[N + 1];
        arr[0] = sum[0] = 0;
        for(int i = 1; i <= N; i++){
            cin >> arr[i];
            sum[i] = sum[i-1] + arr[i];
        }
        int l = 0, r = N + 1;
        for(int i = 0; i <= N; i++){
            for(int j = i + 2; j <= N; j++){
                if(j - i < r - l && isPrime(sum[j] - sum[i])){
                    l = i;
                    r = j;
                    //printf("%d - %d\n", l, r);
                }
            }
        }
        if(r == N+1){
            printf("This sequence is anti-primed.\n");
        } else {
            printf("Shortest primed subsequence is length %d:", r - l);
            for(int i = l + 1; i <= r; i++){
                printf(" %d", arr[i]);
            }
            printf("\n");
        }
    }
}
