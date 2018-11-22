#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;


string s;
int h, m;

int main(){
    while(cin >> s){
        int l = s.length();
        int k;
        for(int i = 0 ; i < l; i++){
            if(s[i] == ':') k = i;
        }
        //cout << k << endl;
        //cout << s.substr(0, k) << "  " << s.substr(k+1, l) << endl;
        h = stoi(s.substr(0, k));
        //cout << h << endl;
        m = stoi(s.substr(k + 1, l));
        if(!m && !h) return 0;
        int totalMin = (60*h + m)%(60 * 12);
        //cout << m << endl;
        float hTheta = totalMin/(2+0.0);//every 60 min, go 30 deg
        float mTheta = 6.0*m;//5 min, go 30 deg => 1 min/ 6deg.
        //cout << hTheta << ", " << mTheta << endl;
        printf("%.3f\n", min(360 - abs(hTheta - mTheta), abs(hTheta - mTheta)));
    }
}

