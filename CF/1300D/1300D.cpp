#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e5;

int N, x, y;

pii points[maxN], vecs[maxN], r;

pii operator-(pii a, pii b){ //vector AB
    return {b.F - a.F, b.S - a.S};
}

pii operator+(pii a, pii b){ //vector AB
    return {b.F + a.F, b.S + a.S};
}

int main(){
    cin >> N;
    if(N % 2){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        points[i] = {x, y};
    }
    for(int i = 0; i < N; i++){
        vecs[i] = points[i] - points[(i - 1 + N) % N];
    }
    for(int i = 0; i < N; i++){
        r = vecs[i] + vecs[(i + N / 2) % N];
        if(r.F != 0 || r.S != 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
