#include <iostream>
#include <string.h>
using namespace std;

string ins, _t;
int memory[100 + 5], c, pointer;

int mod(int a, int m){
    if(a >= 0) return (a % m);
    else return a + m; //assuming the a isn't too small ofc
}

int main(){
    //cout << -1 % 100 << endl;
    //printf("%02X", 1);
    cin >> c;
    getline(cin, _t);
    for(int k = 1; k <= c; k++){
        //if(k > 1) printf("\n");
        getline(cin, ins);
        //cout << endl;
        //cout << ins << endl;
        printf("Case %d:", k);

        int l = ins.length();
        pointer = 0;
        for(int i = 0 ; i < 100; i++){
            memory[i] = 0;
        }
        for(int i = 0 ; i < l; i++){
            if(ins[i] == '>'){
                pointer++;
            } else if(ins[i] == '<'){
                pointer--;
            } else if(ins[i] == '+'){
                memory[pointer]++;
            } else if(ins[i] == '-'){
                memory[pointer]--;
            }
            memory[pointer] = mod(memory[pointer], 256);
            pointer = mod(pointer, 100);
        }
        for(int i = 0 ; i < 100; i++){
            //if(i > 0) printf(" ");
            printf(" %02X", memory[i]);
        }
        printf("\n");
    }
}

