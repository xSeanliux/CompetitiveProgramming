#include <iostream>
using namespace std;

unsigned long long int B, S, c = 0;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b){
    return (b) ? gcd(b, a % b) : a;
}

int main(){
    while(cin >> B >> S){ //value = S/B
        if(!(B | S)) return 0;
        printf("Case %d: ", ++c);
        unsigned long long int g = gcd(B, S);

        unsigned long long int nB = B - 1, nS = S - 1;
        B /= g;
        S /= g;
        if(S > B) S = B = 1;
        if(!nB){
            nS = nB = 1;
            cout << ":-\\" << endl;
            continue;
        } else if(nS){
            g = gcd(nB, nS);
            nB /= g;
            nS /= g;
            if(nS >= nB) nS = nB = 1;
        }

        // S/B > nS/nB implies S * nB >
        if(S * nB > B * nS){
            cout << ":-(" << endl;
        } else if(S * nB == B * nS){
            cout << ":-|" << endl;
        } else {
            cout << ":-)" << endl;
        }
    }
}
