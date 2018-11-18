#include <iostream>
using namespace std;
int N, a, b, c;
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a >> b >> c;
        int maxi = max(a,max(b, c));
        int mini = min(a,min(b, c));
        //cout << "SS " <<  maxi << " " << mini << endl;
        if(a > mini && a < maxi){
            cout << "Case " << i << ": " << a << endl;
        }else if(b > mini && b < maxi){
            cout << "Case " << i << ": " << b << endl;
        } else {
            cout << "Case " << i << ": " << c << endl;
        }

    }
    return 0;

}

