#include <iostream>
#include <algorithm>
using namespace std;

int T, N, a, b;
bool flag = false;

struct Obj{
    int a, b, index;
    Obj(int a, int b, int ind): a(a), b(b), index(ind){}
    Obj(){}
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        Obj arr[N];
        for(int i = 0; i < N; i++){
            cin >> a >> b;
            arr[i] = Obj(a, b, i + 1);
        }
        sort(arr, arr + N, [](const Obj a, const Obj b){
            return a.a * b.b < a.b * b.a;
        });
        if(!flag) flag = true;
        else cout << endl;
        cout << arr[0].index;
        for(int i = 1; i < N; i++){
            cout << " " << arr[i].index;
        }
        cout << endl;
    }
}
