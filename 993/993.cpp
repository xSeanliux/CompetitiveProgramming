#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int ans[1000000];
long long int N, c, head;

int main(){
    cin >> c;
    for(int ik = 0; ik < c; ik++){
        cin >> N;
        if(!N || N == 1){
            cout << N << endl;
            continue;
        }
        head = 0;
        for(int i = 9; i > 1; i--){
            while(!(N % i)){
                N /= i;
                ans[head] = i;
                head++;
            }
        }
        sort(ans, ans + head);
        if(N == 1){
            for(int i = 0 ;i < head; i++){
                cout << ans[i];
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
