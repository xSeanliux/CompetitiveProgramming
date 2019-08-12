#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, a, b;
vector<int> deg;

int main(){
    cin >> N;
    deg.resize(N + 1);
    fill(deg.begin(), deg.end(), 0);
    for(int i = 0; i < N - 1; i++){
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    bool isGood = true;
    for(int i = 1; i <= N; i++){
        if(deg[i] == 2){
            isGood = false;
            break;
        }
    }
    if(isGood){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
