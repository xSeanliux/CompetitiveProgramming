#include <iostream>
#include <set>
using namespace std;

set <unsigned long long int> ncnt, acnt;
unsigned long long int N, X, t, optim;
bool flag = false;

int main(){
    cin >> N >> X;
    optim = 100; //INF
    for(int i = 0 ; i < N; i++){
        cin >> t;
        if(ncnt.count(t)){
            cout << 0 << endl;
            return 0;
        }
        ncnt.insert(t); //1 means not AND yet.
    }
    bool hasDupe = false;
    for(set<unsigned long long int, int>::iterator i = ncnt.begin(); i != ncnt.end(); i++){
        unsigned long long int A = (*i & X);
        if(ncnt.count(A) && A != *i){
            cout << 1 << endl;
            return 0;
        }
        if(acnt.count(A)){
            hasDupe = true;
        } else {
            acnt.insert(A);
        }
    }
    if(hasDupe){
        cout << 2 << endl;
    } else {
        cout << -1 << endl;
    }
}
