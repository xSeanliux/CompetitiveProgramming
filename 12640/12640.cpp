#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr[100000 + 5];

string s, cS;
int head;

int main(){
    while(getline(cin, s)){
        int l = s.length();
        cS = "";
        head = 0;
        for(int i = 0; i < l; i++){
            if(s[i] == ' '){
                arr[head] = stoi(cS);
                cS = "";
                head++;
            } else {
                cS += s[i];
                if(i == l-1){
                    arr[head] = stoi(cS);
                    cS = "";
                    head++;
                }
            }
        }
        for(int i = 0; i < head; i++){

        }
        printf("%lld\n", maxSum);
    }
}
