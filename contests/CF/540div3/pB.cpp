#include <iostream>
using namespace std;

long long int n, arr[200005], op[200005], ep[200005], os[200005], es[200005];

int main(){
    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> arr[i];
    ep[0] = arr[0], op[1] = 0;
    for(int i = 1; i < n; i++){
        if(i % 2){
            op[i] = arr[i] + op[i - 2];
            ep[i] = ep[i - 1];
        } else {
            ep[i] = arr[i] + ep[i - 2];
            op[i] = op[i - 1];
        }
    }
    if((n) % 2){
        os[n-1] = arr[n-1]; es[n - 1] = 0;
    } else {
        os[n-2] = 0; es[n - 1] = arr[n-1];
    }
    for(int i = n - 3; i >= 0; i--){
        if(i % 2){
            os[i] = arr[i] + os[i + 2];
            es[i] = es[i+1];
        } else {
            es[i] = arr[i] + es[i + 2];
            os[i] = os[i+1];
        }
    }
    for(int i = 0; i < n; i++){
        cout << op[i] << "  ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << ep[i] << "  ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << os[i] << "   ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << es[i] << "   ";
    }
    cout << endl;
    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        printf("i = %d, val %d, %d\n", i, ep[i - 1] + os[i + 1], op[i - 1] + es[i + 1]);
        if(ep[i - 1] + os[i + 1] == op[i - 1] + es[i + 1]){
            cnt++;
        }
    }
    cout << cnt << endl;
}
