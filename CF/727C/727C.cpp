#include <iostream>
#define f fflush(stdout)
using namespace std;

int N, ans[5005], a, b, c;


int main(){
    cin >> N;
    for(int i = 1; i + 2 <= N; i += 3){
        cout << "? " << i << " " << i + 1 << endl;
        f;
        cin >> a;
        cout << "? " << i + 1 << " " << i + 2 << endl;
        f;
        cin >> b;
        cout << "? " << i << " " << i + 2 << endl;
        f;
        cin >> c;
        ans[i] = (a + b + c) / 2 - b;
        ans[i + 1] = (a + b + c) / 2 - c;
        ans[i + 2] = (a + b + c) / 2 - a;
    }
    if(N % 3 == 1){
        cout << "? " << 1 << " " << N << endl;
        f;
        cin >> a;
        ans[N] = a - ans[1];
    } else if(N % 3 == 2){
        cout << "? " << 1 << " " << N - 1 << endl;
        f;
        cin >> a;
        ans[N - 1] = a - ans[1];
        cout << "? " << 1 << " " << N << endl;
        f;
        cin >> a;
        ans[N] = a - ans[1];
    }
    cout << "!";
    for(int i = 1; i <= N; i++){
        cout << " " << ans[i];
    }
    cout << endl;
    f;
}
