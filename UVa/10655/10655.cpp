#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

long long int p, q, n;
string s;

struct Matrix{
    long long int m[2][2];
};

Matrix id;

Matrix mult(Matrix a, Matrix b){
    Matrix res;
    res.m[0][0] = a.m[0][0]*b.m[0][0] + a.m[0][1] * b.m[1][0];
    res.m[0][1] = a.m[0][0]*b.m[0][1] + a.m[0][1] * b.m[1][1];
    res.m[1][0] = a.m[1][0]*b.m[0][0] + a.m[1][1] * b.m[1][0];
    res.m[1][1] = a.m[1][0]*b.m[0][1] + a.m[1][1] * b.m[1][1];
    return res;
}

Matrix exp(int e){
    //printf("running exp(%d)\n", e);
    if(e == 1) return id;
    else
    {
        Matrix res = exp(e/2);
        res = mult(res, res);
        if(e % 2) res = mult(id, res);
        return res;
    }
}

int main(){

    while(getline(cin, s)){
        if(s == "0 0") return 0;
        int i = 0, j = 0;
        for(;i < s.length(); i++){
            if(s[i] == ' ') break;
        }
        p = (long long int)(stoi(s.substr(0, i)));
        for(j = i+1; j < s.length(); j++){
            if(s[j] == ' ') break;
        }
        q = (long long int)(stoi(s.substr(i + 1, j - i - 1)));
        n = (long long int)(stoi(s.substr(j + 1, s.length())));
        id.m[0][0] = 0;
        id.m[0][1] = 1;
        id.m[1][0] = -q;
        id.m[1][1] = p;
        if(n == 0){
            printf("2\n");
        } else if(n == 1){
            printf("%lld\n", p);
        } else if(n == 2){
            printf("%lld\n", p*p - 2*q);
        } else {
            Matrix m = exp((int)n-1);
            long long int ans = m.m[0][0] * p + m.m[0][1] * (p*p - 2*q);
            printf("%lld\n", ans);
        }
    }
}
