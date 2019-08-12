#include <iostream>
#include <vector>
using namespace std;

int N, M;
int a, b;
vector<int> v;

int main(){
    cin >> N >> M;
    v.resize(N + 1);
    for(int i = 1; i <= N; i++) cin >> v[i];
    while(M--){
        cin >> a >> b;
        swap(v[a], v[b]);
        for(int i = 1; i <= N; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}
