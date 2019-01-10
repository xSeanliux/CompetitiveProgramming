#include <iostream>
using namespace std;

unsigned long long int N, ans;
unsigned long long int table[1000000];
void f(long long int b){
    //cout << "Running f(" << b << ")" << endl;
    if(b > 3){
        if(table[b-1] == 0){
            f(b-1);
        }
        table[b] = table[b-1] + table[b-2]*4 + table[b-3]*2;
        //cout << "table[" << b << "] = " << table[b-1] << " + " << table[b-2]*4 << " + " << table[b-3]*2 << endl;
        //cout << "F("<< b << ") = " << table[b] << endl;
        return;
    } else {
        return;
    }
}


int main(){
    table[0] = 1;
    table[1] = 1;
    table[2] = 5;
    int k;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> k;
        f(k);
        cout << table[k] << endl;
    }


}
