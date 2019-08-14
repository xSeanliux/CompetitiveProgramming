#include <iostream>
#include <vector>
using namespace std;

const int maxN = 150001;

int frq[maxN + 10], N, v;
bool must[maxN + 10];

vector<int> vec[4];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> v;
        frq[v]++;
    }
    for(int k = 0; k < 100; k++){
        for(int i = 1; i <= maxN + 1; i++){
            if(!frq[i]){
                if(frq[i + 1]){
                    frq[i + 1]--;
                    frq[i]++;
                }
            }
        }
        for(int i = maxN + 1; i >= 1; i--){
            if(!frq[i]){
                if(frq[i - 1]){
                    frq[i - 1]--;
                    frq[i]++;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= maxN + 1; i++){
        if(frq[i] > 0) ans++;
    }
    cout << ans << endl;
}

