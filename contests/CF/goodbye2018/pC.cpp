#include <iostream>
#include <set>
using namespace std;

int N;
set<unsigned long long int> s;
int main(){
    cin >> N;
    for(unsigned long long int i = 1; i*i <= N; i++){
        if(!(N % i)){
            unsigned long long int k = N/i;
            s.insert(N/i + i * (N/i - 1) * (N/i) / 2);
            s.insert(N/k + k * (N/k - 1) * (N/k) / 2);
        }
    }
    bool flag = false;
    for(set<unsigned long long int>::iterator i = s.begin(); i != s.end(); i++){
        if(!flag) flag = true;
        else cout << " ";
        printf("%llu", *i);
    }
}
