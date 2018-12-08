#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
string N;
long long int c = 0;
bool isL, festival;

long long int digSum(string s){
    int l = s.length();
    long long int ans = 0;
    for(int i = 0; i < l; i++){
        ans += s[i] - '0';
    }
    return ans;
}





bool can100(string s){
    //cout << s.substr(s.length() - 2) << endl;
    return s.substr(s.length() - 2) == "00";
}


bool can4(string s){
    //cout <<stoi(s.substr(s.length() - 2)) << endl;
    return !(stoi(s.substr(s.length() - 2)) % 4);
}


bool can3(string s){
    return !(digSum(s) % 3);
}

bool can5(string s){
    return !((s[s.length() - 1] - '0') % 5);
}

bool can400(string s){
    return !(stoi(s.substr(s.length() - 4)) % 400);
}

bool can11(string s){
    int l = s.length();
    long long int a = 0, b = 0;
    for(int i = 0; i < l; i++){
        if(i % 2){
            a += s[i] - '0';
        } else {
            b += s[i] - '0';
        }
    }
    //cout << a << " " << b<< endl;
    return !(abs(a-b) % 11);
}

bool isLeap(string s){
    if(can400(s)) return true;
    else if(can100(s)) return false;
    else if(can4(s)) return true;
    else return false;
}


int main(){
    //cout << can11("2000") << endl;
    while(cin >> N){
        if(c != 0){
            printf("\n");
        }
        c++;
        festival = false;
        isL = false;
        if(isLeap(N)){
            printf("This is leap year.\n");
            isL = true;
            festival = true;
        }
        if(can5(N) && can3(N)){
            printf("This is huluculu festival year.\n");
            festival = true;
        }
        if(isL && can11(N) && can5(N)){
            printf("This is bulukulu festival year.\n");
            festival = true;
        }
        if(!festival){
            printf("This is an ordinary year.\n");
        }
    }
}
