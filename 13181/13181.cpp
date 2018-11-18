#include <iostream>
#include <string.h>
using namespace std;

string command;
int lens[500000];
int start, head;
int main(){
    while(getline(cin, command)){
        int l = command.length();
        start = head = 0;
        for(int i = 0 ; i < l; i++){
            if(command[i] == 'X' || i == l-1 && command[i]){
                if((start == 0 && command[0] == '.') || (i == l-1 && command[l-1] == '.') ){ //dont div by two
                    lens[head] = i - start - 1;
                } else {
                    int k = i - start - 1;
                    //cout << k << endl;
                    if(k % 2){
                        lens[head] = (k - 1)/2;
                    } else {
                        lens[head] = k/2 - 1;
                    }
                }
                start = i;
                //cout << head << ": " << lens[head] << ". s: " << start << endl;
                head++;
            }
        }
        int m = 0;
        for(int i = 0 ; i < head; i++){
            if(m < lens[i]){
                m = lens[i];
            }
        }
        printf("%d\n", m);
    }
}
