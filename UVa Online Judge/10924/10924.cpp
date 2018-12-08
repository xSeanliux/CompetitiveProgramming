#include <iostream>
#include <string.h>
using namespace std;


string s;
bool isPrime[10000];

int getVal(char c){
    if('a' <= c && c <= 'z'){
        return (c - 'a' + 1);
    } else if('A' <= c && c <= 'Z'){
        return (c - 'A' + 27);
    } else {
        return -1;
    }
}

void initPrimes(){
    for(int i = 1; i < 10000; i++){
        if(i % 2 == 0){
            isPrime[i] = false;
        } else {
            isPrime[i] = true;
        }
    }
    isPrime[0] = false;
    isPrime[2] = true;
    for(int i = 3; i < 10000; i += 2){
        if(isPrime[i]){
            for(int j = i * i; j < 10000; j += i){
                isPrime[j] = false;
            }
        }
    }
}



int main(){
    initPrimes();
    while(getline(cin, s)){
        int sum = 0;
        int l = s.length();
        for(int i = 0; i < l; i++){
            sum += getVal(s[i]);
        }
        if(isPrime[sum]){
            printf("It is a prime word.\n");
        } else {
            printf("It is not a prime word.\n");
        }
    }
}
