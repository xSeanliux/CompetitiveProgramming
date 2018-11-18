#include <iostream>
using namespace std;
int timearr[100000];
int a[100000], b[100000];
int m, n, t;

int main()
{
    while(cin >> m >> n >> t)
    {
        for(int i = 0; i <= t; i++){
            timearr[i] = 0;
            a[i] = 0;
            b[i] = 0;
        }
        if(n > m){ //n is always smaller
                swap(n, m);
        }
        for(int i = 0; i <= t; i++){
            int q = i/n;
            timearr[i] = q*n ;
            a[i] = q;
        }
        for(int j = 1; j*m <= t; j++){
            if(timearr[t] < timearr[t - j*m] + j*m){
                timearr[t] = timearr[t - j*m] + j*m;
                a[t] = a[t - j*m];
                b[t] = b[t - j*m] + j;
            }
        }

        cout << a[t] + b[t];
        if(t - timearr[t] > 0){
            cout << " " << t - timearr[t];
        }
        cout << endl;


    }





}
