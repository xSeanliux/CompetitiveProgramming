#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
string s;

int main(){
    while(cin >> s){
        //string s = to_string(N);
        sort(s.begin(), s.end()); //smallest
        string news = s;
        if(news[0] == '0' && news.length() > 0){
            int i;
            for(i = 1; i < news.length(); i++){
                if(news[i] != '0'){
                    swap(news[0], news[i]);
                    break;
                }
            }
        }
        long long int a = stoll(news); //biggest
        reverse(s.begin(), s.end());
        long long int b = stoll(s);
        long long int res = abs(a - b);
        printf("%lld - %lld = %lld = %lld * %lld\n", b, a, res, 9, res/9);
    }
}
