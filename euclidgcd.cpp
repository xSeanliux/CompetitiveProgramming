#include <iostream>
using namespace std;

int f(int a, int b){
    if(b == 0){
        return a;
    } else {
        //cout << "Running f(" << b << ", " << a%b << ")." << endl;
        return f(b, a%b);
    }
}


int main(){
    int a,b;
    while(cin >> a >> b){
        cout << f(a, b) << endl;
    }


}
