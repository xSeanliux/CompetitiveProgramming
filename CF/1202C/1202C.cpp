#include <iostream>
#include <math.h>
using namespace std;

int S, a, b, c;

double llog(int x){
    return !x ? 0 : log2(x);
}

int main(){
    cin >> S >> a >> b >> c;
    double sum = llog(a) + llog(b) + llog(c);
    cout << S * llog(a) / sum << " ";
    cout << S * llog(b) / sum << " ";
    cout << S * llog(c) / sum << endl;

}
