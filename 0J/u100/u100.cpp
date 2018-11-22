#include <iostream>
using namespace std;

int a, b;



int g(int num){


    if(num == 1){
        //cout << "Length: " << currentLen << endl;
        return 1;
    } else {
        if(num % 2 == 0){
            return 1+g(num/2);
        } else{

            return 1+g(3*num+1);
        }
    }
}



int main(){
    bool flag = true;
while(cin >> a >> b){
    flag = true;
    if(b < a){

        int t = b;
        b = a;
        a = t;
        flag = false;
    }
    int ans = 0;
    for(int i = a; i <= b; i++){
        int k = g(i);
        if(k > ans){
            ans = k;
        }

        //cout << "QQ" <<  f(0, i) << endl;
        //cout << lengths[i] << endl;
    }

    if(flag){
        cout << a << " " <<  b << " " << ans << endl;

    } else {
        cout << b << " " <<  a << " " << ans << endl;

    }


}


}
