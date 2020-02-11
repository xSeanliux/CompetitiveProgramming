#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<int> a, b, pos;
int N;

int main(){
    ericxiao;
    cin >> N;
    a.resize(N);
    b.resize(N);
    pos.resize(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        cin >> b[i];
        pos[b[i]] = i;
    }
    int cind = -1;
    for(int i = 0; i < N; i++){
        if(pos[a[i]] < cind){
            cout << N - i << endl;
            return 0;
        } else {
            cind = pos[a[i]];
        }
    }
    cout << 0 << endl;
}
