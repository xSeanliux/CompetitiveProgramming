#include <iostream>
using namespace std;

using namespace std;

int reverseNum(int num){
    int a = 0;
    while(num > 10){
        a += num % 10;
        num /= 10;
        a*= 10;

    }
    a += num;
    return a;
}

bool isPrime(int N){
    for(int i = 2; i*i < N; i++){
        if(N % i == 0) return false;
    }
    return true;
}

int main(){
    int N, reverseN;
    while(cin >> N){
        reverseN = reverseNum(N);
        //cout << reverseN << endl;
        if(isPrime(N) && isPrime(reverseN) & reverseN != N){
            cout << N << " is emirp." << endl;
        } else if(isPrime(N) && isPrime(reverseN)){
            cout << N << " is prime." << endl;

        }else if (isPrime(N)){
            cout << N << " is prime." << endl;
        } else {
            cout << N << " is not prime."<< endl;
        }
    }
}
