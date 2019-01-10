#include <iostream>
#include <math.h>
#include <vector>
#define PI acos(-1)
#define root(x) Complex(cos(2.0*PI/x), sin(2.0*PI/x))
using namespace std;

struct Complex{
    double im, re;
    Complex(double re, double im): im(im), re(re)
        {
        }
    Complex(){}
};

Complex add(Complex a, Complex b){
    return Complex(a.re + b.re, a.im + b.im);
}

Complex mult(Complex a, Complex b){
    return Complex(a.re*b.re - a.im*b.im, a.im*b.re + a.re*b.im);
}

Complex subtract(Complex a, Complex b){
    return Complex(a.re - b.re, a.im - b.im);
}

int deg, cnt = 0;
vector<Complex> f, res;

vector<Complex> fft(vector<Complex> f){
    if(f.size() == 1){
        return f;
    }
    vector<Complex> o, e;
    for(int i = 0; i < f.size(); i++){
        if(i % 2){
            o.push_back(f[i]);
        } else{
            e.push_back(f[i]);
        }
    }
    Complex omega = root(1);
    Complex omega_n = root(f.size());
    o = fft(o);
    e = fft(e);
    vector<Complex> _res;
    _res.reserve(f.size() + 1);
    for(int i = 0; i < f.size(); i++)
        _res.push_back(Complex());
    for(int i = 0; i < f.size()/2; i++){
        _res[i             ] = add(e[i], mult(omega, o[i]));
        _res[i + f.size()/2] = subtract(e[i], mult(omega, o[i]));
        omega = mult(omega, omega_n);
    }
    return _res;
}

int main(){
    cin >> deg;
    for(int i = 0; i < deg; i++){
        Complex c;
        cin >> c.re >> c.im;
        f.push_back(c);
    }
    res = fft(f);
    for(int i = 0; i < res.size(); i++){
        printf("(%f, %f)\n", res[i].re, res[i].im);
    }

}
