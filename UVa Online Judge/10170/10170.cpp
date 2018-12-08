#include <iostream>
using namespace std;

double s, d;

int main(){
    while(cin >> s >> d){
        double sum = s;

        while(sum < d){
            s++;
            sum += s;
        }
        printf("%.0f\n", s);
    }
}
