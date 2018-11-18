#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

int bit[MAX], biti[MAX], d[MAX], di[MAX], arr[MAX], arri[MAX], com1, com2, com3, N;
string com;

int v2(int N){
    int res = 1;
    while(!(N % 2)){
        res *= 2;
        N /= 2;
    }
    return res;
}



int getPrefixSum(int r){
    int res = 0, res2 = 0;
    cout << "bits: " << endl;
    for(int i = r; i >= 1; i -= v2(i)){
        cout << bit[i] << " ";
        //cout << "i = " << i << endl;
        res += bit[i];
    }
    cout << endl << "bitiL " << endl;
    res *= r + 1;
    for(int i = r; i >= 1; i -= v2(i)){
        cout << biti[i] << " ";
        //cout << "i = " <<i << endl;
        res2 += biti[i];
    }
    cout << endl;
    return res - res2;
}


void buildBit(){
    //biti[1] = bit[1] = d[1];
    for(int i = 1; i <= N; i++){
        //to get bit[i]
        bit[i] = d[i];
        int K = v2(i), currentIndex = i - 1;
        //cout << "i = " << i << endl;
        while(currentIndex >= i - K + 1){
            bit[i] += bit[currentIndex];
            currentIndex -= v2(currentIndex);
        }
    }
    for(int i = 1 ; i <= N; i++){
            cout << d[i] << " ";
        }
        cout << endl;
    for(int i = 1 ; i <= N; i++){
            cout << bit[i] << " ";
        }
        cout << endl;

    for(int i = 1; i <= N; i++){
        int currentIndex = i - 1, K = v2(i);
        //to get biti[i]
        biti[i] = d[i] * i;
        //cout << "i = " <<i << endl;
        while(currentIndex >= i - K + 1){
            //cout << "bit[" << i << "] += " << biti[currentIndex] << endl;
            biti[i] += biti[currentIndex];
            currentIndex -= v2(currentIndex);
        }
    }
}

int change(int s, int e, int val){ //lol
    d[s] += val;
    d[e + 1] -= val;
    //change bit and biti
    buildBit();
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        if(i == 1){
            d[i] = arr[i];
        } else {
            d[i] = arr[i] - arr[i-1];
        }
        di[i] = i * d[i];
        arri[i] = i * arr[i];
    }
    buildBit();
    while(cin >> com){
        if(com == "a"){ //change
            cin >> com1 >> com2 >> com3;
            change(com1, com2, com3);
        } else if(com == "b"){ //output prefix
            cin >> com1;
            cout << getPrefixSum(com1) << endl;
        }
        cout << endl;
        int a = 0;
        for(int i = 1 ; i <= N; i++){
            cout << i << " ";
        }
        cout << endl << endl;
        for(int i = 1 ; i <= N; i++){
            a += d[i];
            cout << a << " ";
        }
        cout << endl;
        for(int i = 1 ; i <= N; i++){
            cout << d[i] << " ";
        }
        cout << endl;
        for(int i = 1 ; i <= N; i++){
            cout << bit[i] << " ";
        }
        cout << endl;
        for(int i = 1 ; i <= N; i++){
            cout << biti[i] << " ";
        }
        cout << endl;
    }
}
