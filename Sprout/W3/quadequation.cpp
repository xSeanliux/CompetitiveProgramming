#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int T, n;
long double a, b, c;

struct Eq{
    long double a, b, c;
    long double eval(double x){
        return a * ( x - b ) * ( x - b ) + c;
    }
};

vector<Eq> eqs;

long double getMax(double x){
    long double currentMax = -2e9;
    for(int i = 0; i < n; i++){
            currentMax = max(currentMax, eqs[i].eval(x));
    }
    return currentMax;
}


int main(){
    cin >> T;
    cout << fixed << setprecision(5);
    while(T--){
        cin >> n;
        eqs.clear();
        eqs.resize(n);
        for(int i = 0; i < n; i++){
            cin >> eqs[i].a >> eqs[i].b >> eqs[i].c;
        }
        long double l = 0.0, r = 300.0, ml = (r + 2 * l) / 3, mr = (2 * r + l) / 3;
        //cout << "l : " << l << ", r : " << r << ", ml : " << ml << ", mr : " << mr << endl;
        while(r - l > 1e-9){
            if(getMax(ml) < getMax(mr)){
                r = mr;
            } else {
                l = ml;
            }
            ml = (r + 2 * l) / 3, mr = (2 * r + l) / 3;
        //cout << "l : " << l << ", r : " << r << ", ml : " << ml << ", mr : " << mr << endl;
        }
        long double minVal = getMax(ml), minArg = ml;
        if(getMax(0) < minVal){
            minArg = 0;
            minVal = getMax(0);
        }
        if(getMax(300) < minVal){
            minArg = 300;
            minVal = getMax(300);
        }
        cout << minVal << endl;
    }
}
