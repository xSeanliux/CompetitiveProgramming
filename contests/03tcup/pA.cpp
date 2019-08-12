#include <iostream>
#include <algorithm>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);
using namespace std;


long long int N, k, arr[(int)1e6 + 10], s = 0;
int main(){
    ericxiao;
    cin >> N;
    int oc = 0, no = 0;
    for(int i = 0; i < N; i++){
        cin >> k;
        s ^= k;
        oc += (k == 1);
    }
    //1 2 ->
    if((oc == N && !s) || ((oc != N) && s > 0)){
        cout << "Eric" << endl;
    } else{
        cout << "Kevin" << endl;
    }
}
