#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string a, currentSum;

string sum(string a, string b){

    if( a.length() <  b.length()) swap(a, b);
    int la = a.length();
    int lb = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    string result = "";
    int sum;
    for(int i = 0; i < la; i++){
        if(i < lb){
            sum = (a[i] - '0') + (b[i] - '0') + carry;
        } else {
            sum = (a[i] - '0') + carry;
        }

        char dig = to_string(sum%10)[0];
        carry = sum/10;
        result += dig;
    }
    if(carry) result += to_string(carry);
    reverse(result.begin(), result.end());
    return result;
}

int main(){

    while(cin >> a){
        if(a == "0"){
            cout << currentSum << endl;
        } else{
            currentSum = sum(a, currentSum);
        }
    }
}
