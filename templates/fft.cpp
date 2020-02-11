#include <iostream>
#include <complex>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define PI (long double)(3.14159265358979311600)
#define cd complex<long double>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const cd I (0.0, 1.0);

void FFT(vector<cd> &f, int inv){ //1 for FFT, -1 for inverse FFT
    if(f.size() == 1) return;
    vector<cd> o, e;
    for(int i = 0; i < f.size(); i++){
        if(i % 2) o.push_back(f[i]);
        else e.push_back(f[i]);
    }
    FFT(o, inv);
    FFT(e, inv);
    cd omega = 1;
    cd omega_n(cos(inv * 2*PI/f.size()), sin(inv * 2*PI/f.size()));
    for(int i = 0; i < f.size()/2; i++){
        f[i             ] = e[i] + omega * o[i];
        f[i + f.size()/2] = e[i] - omega * o[i];
        omega = omega * omega_n;
    }
}

int N, M;
vector<cd> coef1, coef2;
string a, b;
int main(){
    ericxiao;
    cin >> a >> b;
    N = a.length(), M = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int l;
    for(l = 1; l < max(N, M); l++) if((1LL << (l - 1)) >= max(N, M)) break;
    coef1.resize((1LL << l));
    coef2.resize((1LL << l));

    int ind = 0, t;
    for(cd &i : coef1){
        if(ind < N) t = (a[ind] - '0');
        if(ind >= N) t = 0;
        i = cd(t, 0);
        ind++;
    }
    ind = 0;
    for(cd &i : coef2){
        if(ind < M) t = (b[ind] - '0');
        if(ind >= M) t = 0;
        i = cd(t, 0);
        ind++;
    }
    /*
    for(cd &i : coef1){
        cout << i.real() << " " << i.imag() << endl;
    }
    cout << endl;
    for(cd &i : coef2){
        cout << i.real() << " " << i.imag() << endl;
    }
    cout << endl;
    */

    FFT(coef1, 1);
    FFT(coef2, 1);
    vector<cd> res;
    res.resize(coef1.size());

    for(int i = 0; i < res.size(); i++){
        res[i] = coef1[i] * coef2[i];
    }
    string ans = "";
    FFT(res, -1);
    int v, c = 0;
    for(int i = 0; i < res.size(); i++){
        res[i] /= res.size();
        //cout << res[i].real() + c<< endl;
        v = (int)(round(res[i].real())) + c;
        ans = (char)(v % 10 + '0') + ans;
        c = v / 10;
    }
    if(c) ans = (char)(c + '0') + ans;
    for(int i = 0; i < ans.length(); i++){
        if(ans[i] != '0'){
            cout << ans.substr(i, ans.length()) << endl;
            return 0;
        }
    }



}
