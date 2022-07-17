#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 3e5 + 326;

int A[maxN], B[maxN], N, Q, M, val[maxN], fib[maxN], nzc;

inline int add(int a, int b) {
    return a + b >= M ? a + b - M : a + b;
}

inline int sub(int a, int b) {
    return a - b < 0 ? a - b + M : a - b;
}

inline void modify(int p, int v) {
    //cout << "running modify(" << p << ", " << v << ")\n";
    nzc -= (val[p] != 0);
    val[p] = add(val[p], v);
    nzc += (val[p] != 0);
}

int main() {
    ericxiao
    cin >> N >> Q >> M;
    fib[1] = fib[2] = 1;
    for(int i = 3; i < maxN; i++) fib[i] = add(fib[i - 1], fib[i - 2]);
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= N; i++) cin >> B[i];
    N += 10;
    for(int i = 1; i <= N; i++) A[i] = sub(A[i], B[i]); //A[i] is now target 
    val[1] = A[1]; 
    val[2] = sub(A[2], A[1]);
    nzc = 0;
    for(int i = 3; i <= N; i++) val[i] = sub(A[i], add(A[i - 1], A[i - 2]));
    for(int i = 1; i <= N; i++) nzc += (val[i] != 0);
    while(Q--) {
        int l, r;
        char c;
        cin >> c >> l >> r;
        //cout << "len = " << r - l + 1 << endl;
        if(c == 'A') {
           modify(l, 1);
           if(l == r){
               modify(r + 1, M - 1);
               modify(r + 2, M - 1);
           } else {
               modify(r + 1, sub(0, fib[r - l + 2]));
               modify(r + 2, sub(0, fib[r - l + 1]));
           }
        } else {
           modify(l, M - 1);
           if(l == r) {
               modify(r + 1, 1);
               modify(r + 2, 1);
           } else {
               modify(r + 1, fib[r - l + 2]);
               modify(r + 2, fib[r - l + 1]);
           }
        }
        cout << ((nzc == 0) ? "YES" : "NO") << '\n';
    }
}
