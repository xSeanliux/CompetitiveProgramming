#include <iostream>
using namespace std;

int N, c;

int f(int N){
    int sum = 0;
    int k = N;
    while(N > 0){
        sum += N % 10;
        N -= N%10;
        N /= 10;
    }
    return sum + k;

}


int main(){
    cin >> c;
    bool flag;
    for(int as = 0; as < c; as++){
        cin >> N;
        flag = false;
        for(int i = max(0, N-99); i < N; i+=1){
            //cout << i << endl;
            //if(((N - i) % 3) != 1){
                if(f(i) == N && !flag){
                    cout << i << endl;
                    flag = true;
                }
            //}
        }
        if(!flag){
            cout << 0 << endl;
        }
    }
}
