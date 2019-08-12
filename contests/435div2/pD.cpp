#include <iostream>
#define flush fflush(stdout)
using namespace std;

int N, ca, na;
string cg, ng;

int main(){
    cin >> N;
    cg = "";
    for(int i = 0; i < N; i++) cg += "0";
    cout << "? " << cg << endl;
    flush;
    cin >> ca;
    int l = 0, r = N, m = (l + r) / 2, delta;
    while(l + 1 < r){
        //cout << "L = " << l << ", R  = " << r << endl;
        ng = "";
        for(int i = 0; i < m; i++) ng += '1';
        while(ng.length() < N) ng += '0';
        cout << "? " << ng << endl;
        flush;
        cin >> na;
        delta = na - ca; //zeroes - ones
        if(delta == (m - l) || -delta == (m - l)){
            //cout << "HMM" << endl;
            int k;
            string c = "";
            for(int i = 0; i < r; i++) c += '1';
            while(c.length() < N) c += '0';
            cout << "? " << c << endl;
            flush;
            cin >> k;
            if(k - na == (r - l) || na - l == (r - l)){
                break;
            } else {
                l = m;
            }
        }
        else r = m;
        m = (l + r) / 2;
        ca = na;
        //cout << "Now, L = " << l << ", R  = " << r << endl;
    }
    m--;
    //position is in m + 1, right?
    string zf = "", of = "";
    for(int i = 1; i < m; i++) zf += '1';
    zf += "01";
    while(zf.length() < N) zf += '0';
    for(int i = 1; i < m; i++) of += '1';
    of += "10";
    while(of.length() < N) of += '0';
    int zfA, ofA;
    cout << "? " << zf << endl;
    flush;
    cin >> zfA;

    cout << "? " << of << endl;
    flush;
    cin >> ofA;

    if(ofA < zfA){
        cout << "! " << m + 2 << " " << m + 1 << endl;
    } else {
        cout << "! " << m + 1 << " " << m + 2 << endl;
    }
    flush;
    return 0;
}
