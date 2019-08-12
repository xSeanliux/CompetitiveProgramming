#include <iostream>
#include <map>
using namespace std;

int a, b, N, x;
map<int, int> mp;

int main(){
    cin >> N;
    a = 0; b = 0;
    for(int i = 0; i < N; i++){
        cin >> x;
        a = max(a, x);
        mp[x]++;
    }
    for(int i = 1; i <= a; i++){
        if(mp.count(i) && !(a % i)){
            mp[i]--;
        }
    }
    for(int i = 0; i <= (int)1e4; i++){
        if(mp.count(i) && mp[i] > 0){
            b = max(b, i);
        }
    }
    cout << a << " " << b << endl;
}
