#include <iostream>
#define double long double
#define int long long int
using namespace std;

const int maxN = 1e6;
const double eps = 1e-10;
int N, arr[maxN + 10], L, R;

bool canDo(double avg){
    double newArr[N + 10];
    newArr[0] = arr[0] - avg;
    for(int i = 1; i < N; i++) newArr[i] = newArr[i-1] + arr[i] - avg;
    int minAt = 0, minVal = newArr[0];
    if(newArr[1] > 0){
        L = 0; R = 1; return true;
    }
    for(int i = 2; i < N; i++){
        if(newArr[i] > eps){
            L = 0;
            R = i;
            return true;
        } else if(newArr[i] - minVal > 0){
            L = minAt + 1;
            R = i;
            return true;
        } else if(minVal > newArr[i]){
            minAt = i;
            minVal = newArr[i];
        }
    }
    return false;
}

int gcd(int a, int b){
    return(!b ? a : gcd(b, a % b));
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    double u = 1e9 + 10.0, l = 0, m = (u + l) / 2;
    while(l + eps < u){
        if(canDo(m)){
            l = m;
        } else u = m;
        m = (u + l) / 2;
    }
    int val = 0;
    for(int i = L; i <= R; i++) val += arr[i];
    int d = R - L + 1, g = gcd(val, d);
    d /= g;
    val /= g;
    cout << val << "/" << d << endl;

}
