#include <iostream>
using namespace std;

long long int n, q, a, arr[1000005], sum[1000005];


int main(){
    cin >> n >> q;
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    sum[0] = arr[0];
    for(int i = 1 ; i < n; i++){
        sum[i] = arr[i] + sum[i-1];
    }
    for(int kk = 0; kk < q; kk++){
        cin >> a;
        if(a == 1){
            int l, r, c;
            cin >> l >> r >> c;
            for(int i = l; i <= r; i++){
                arr[i] %= c;
            }
            sum[0] = arr[0];
            for(int i = 1 ; i < n; i++){
                sum[i] = arr[i] + sum[i-1];
            }
        } else if(a == 2){
            int l, r;
            cin >> l >> r;
            long long int ans = sum[r];
            if(l > 0)
                ans -= sum[l-1];
            cout << ans << endl;
        }

        /*
        cout << "a: " << a << endl;
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++){
            cout << sum[i] << " ";
        }
        cout << endl;
        */
    }
}
