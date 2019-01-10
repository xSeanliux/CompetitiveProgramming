#include <iostream>
#include <bitset>
using namespace std;

long long int N, mask = 2147483647;
string s;

int main(){
    while(cin >> N){
        //convert to binary
        s = "";
        cout << N << " converts to ";
        bool isneg = (N < 0);
        if(isneg) {
            N = ~N;
            while(N){
                s = ((N % 2) ? '0' : '1') + s;
                N /= 2;
            }
            while(s.length() < 32) s = '1' + s;
        } else {
            while(N){
                s = ((N % 2) ? '1' : '0') + s;
                N /= 2;
            }
            while(s.length() < 32) s = '0' + s;
        }
        //cout << s << endl;
        string s1 = s.substr(0, 8), s2 = s.substr(8, 8), s3 = s.substr(16, 8), s4 = s.substr(24, 8);
        //cout << s4 + s3 + s2 + s1 << endl;
        bitset<32> k(s4 + s3 + s2 + s1);
        printf("%d\n", (int)(k.to_ulong()));
    }
}
