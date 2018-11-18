#include <iostream>
using namespace std;
int main(){
    int a, m, n, ans;
    cin >> a;
    for(int i = 1; i <= a; i++){
            cin >> m >> n;
            ans = 0;
            for(int i = 0; i*i <= n; i++){
                if(i * i >= m){
                    ans += i*i;
                }
            }
            cout << "Case " << i <<": "<< ans << endl;


    }



    }



