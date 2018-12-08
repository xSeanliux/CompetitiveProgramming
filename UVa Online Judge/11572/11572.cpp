#include <iostream>
#include <set>
using namespace std;

set <int> s;
int L, R, maxLen, c, N, arr[1000005];

int main(){
    cin >> c;
    for(int ka = 0; ka < c; ka++){
        s = set <int>();
        cin >> N;
        for(int i = 0 ; i < N; i++){
            cin >> arr[i];
        }
        L = 0,  R = 0, maxLen = 0;
        while(R != N){
            if(!s.count(arr[R])){
                s.insert(arr[R]);
                R++;
            } else {
                s.erase(arr[L]);
                L++;
            }
            if(R - L > maxLen){
                //cout << "From " << L << " to " << R << ", maxLen = " << maxLen << endl;
                maxLen = R - L;
            }
        }
        cout << maxLen << endl;
    }
}
