#include <iostream>
#include <vector>
using namespace std;

int N, Q, l, r;
vector<int> vec;

int main(){
    cin >> N >> Q;
    vec.resize(N + 1);
    for(int i = 1; i <= N; i++) cin >> vec[i];
    for(int i = 0; i < Q; i++){
        cin >> l >> r;
        int maxVal = vec[l], x = 0;
        for(int i = 0; i < (1 << (r - l + 1)); i++){
            for(int j = 0; j < 10; j++){
                if(((1 << j) & i) > 0){
                    x ^= vec[j + l - 1];
                }
            }
            maxVal = max(maxVal, x);
        }

        cout << maxVal << endl;
    }
}
