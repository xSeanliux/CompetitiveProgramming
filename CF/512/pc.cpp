#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
string s;
int l;
stack <int> divs;
bool canBeDone = false;
void checkisOk(int N){ //check if can be split into N as the golden ticket sum
    int currentSum = 0;
    //cout << "Checking N = " << N << endl;
    for(int i = 0 ; i < l; i++){
        currentSum += s[i] - '0';
        if(currentSum == N){
            currentSum = 0;
            if(i == l-1){
                canBeDone = true;
                //cout << "Can be done" << endl;
            }
        } else if(currentSum > N){
            //cout << "Exit at i = " << i << endl;
            return;
        } else if(i == l-1){
            canBeDone = true;
            //cout <<"Can be done!" << endl;
        }
    }
}

int main(){
    cin >> l >> s;
    int sum = 0;
    for(int i = 0 ; i < l; i++){
        sum += s[i] - '0';
    }
    if(!sum) canBeDone = true;
    for(int i = 1; i < sum; i++){
        if(!(sum % i)){
            divs.push(i);
        }
    }
    while(!canBeDone && !divs.empty()){
        checkisOk(divs.top());
        divs.pop();
    }
    if(canBeDone){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
