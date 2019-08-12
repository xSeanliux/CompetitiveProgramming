#include <iostream>
using namespace std;

int N;



void extgcd(int a, int b, long long int &x, long long int &y){
    if(!b){ x = 1; y = 0; }
    else { extgcd(b, a % b, y, x); y -= x*(a/b); }
}

long long  minverse(int a, int m){
    long long int d, x, y;
    extgcd(a, m, x, y);
    while(x < 0) x += m;
    return x;
}




int main(){
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) cin >> arr[i];
    //arr[i] = x_{2*i + 1}
    for(long long int a = 0; a < 10001; a++){
        //cout << "a = " << a << endl;
        long long int b = ((long long)(arr[1] - a*a*arr[0] + 10001*10001) * minverse(a+1, 10001)) % 10001, x = arr[0];
        bool matches = true;
        for(int i = 1; i < N; i++){
            x = (a*a*x + a*b + b) % 10001;
            if(arr[i] != x){
                //cout << "Out at x_" << 2*i + 1 << " = " << x << " but actually " << arr[i] << endl;
                matches = false;
                break;
            }
        }
        if(matches){
            //cout << a << ", " << b << endl;
            x = arr[0];
            x = (a*x + b) % 10001;
            for(int i = 0; i < N; i++){
                printf("%d\n", x);
                x = (a*a*x + a*b + b) % 10001;
            }
            return 0;
        }


    }

}
