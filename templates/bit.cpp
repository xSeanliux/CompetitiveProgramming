#include <iostream>
using namespace std;

int N, arr[1000], bit[1000];


int mP(int N){
    if(!N)
        return 0;
    int k = 1;
    while(!(N % 2)){
        N /= 2;
        k *= 2;
    }
    return k;
}

void update(int ind, int val){
    int diff = val - arr[ind];
    for(int i = ind; i <= N; i += mP(i)){
        bit[i] += diff;
    }
}


int pref(int ind){
    int ans = 0;
    for(int i = ind; i >= 1; i -= mP(i) ){
        ans += bit[i];
    }
    return ans;
}

void initTree(){
    for(int i = 1; i <= N; i++){
        int maxPow = mP(i);
        int target = i - maxPow + 1;
        int currentIndex = i-1;
        cout << "Set current: " << i << ", target: " << target << endl;
        while(currentIndex >= target){
            bit[i] += bit[currentIndex];
            cout << "bit[" << i << "] += " << arr[currentIndex] << endl;
            currentIndex -= mP(currentIndex);
        }
        bit[i] += arr[i];
    }
}


int main(){
    cin >> N;
    for(int i = 1 ; i <= N; i++){
        cin >> arr[i];
    }
    initTree();
    for(int i = 1 ; i <= N; i++){
        cout << bit[i] << " ";
    }
    cout << endl;
    update(1, 10);
    for(int i = 1 ; i <= N; i++){
        cout << bit[i] << " ";
    }
    cout << "pref(3) : " << pref(3) << endl;
}
