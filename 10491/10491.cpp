#include <iostream>
using namespace std;

double cows, cars, show;

int main(){
    while(cin >> cows >> cars >> show){
        int total = cows + cars;
        double prob = (cars*cars - cars + cows*cars)/(total * (total - show - 1));
        printf("%.05f\n", prob);
    }
}
