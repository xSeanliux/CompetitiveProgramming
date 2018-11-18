#include <iostream>
#include <math.h>
using namespace std;

double a[1000 + 5];
double people, total;
int main(){
    while(cin >> people){
        if(people == 0) return 0;
        total = 0;
        for(int i = 0; i < people; i++){
            cin >> a[i];
            total += a[i];
        }

        double avg = total/people;
        avg = round(avg*100)/100;
        //cout << "A: " << avg << endl;
        double moneyP = 0;
        double moneyN = 0;
        double money;
        for(int i = 0; i < people; i++){
            if(a[i] < avg) moneyP += round((avg - a[i])*100) / 100;
            if(a[i] > avg) moneyN += round((avg - a[i])*100) / 100;
            //cout << money << endl;
        }
        money = (-moneyN < moneyP) ? -moneyN : moneyP;

        printf("$%.2f\n", money);
    }
}
