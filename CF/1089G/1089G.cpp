#include <iostream>
using namespace std;

long long int T, days, arr[7], sum;

int main(){
    cin >> T;
    while(T--){
        cin >> days;
        sum = 0;
        for(int i = 0; i < 7; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        if(days <= sum){
            int minAns = 2147483647;
            for(int i = 0; i < 7; i++){
                if(arr[i]){ //start sim
                    int ind = 0, currentSum = 0;
                    while(currentSum < days){
                        currentSum += arr[(ind++ + i) % 7];
                    }
                    minAns = min(minAns, ind);
                }
            }
            printf("%d\n", minAns);
        } else {
            int minAns = 2147483647;
            for(int i = 0; i < 7; i++){
                if(arr[i]){ //start sim
                    int _currentDays = days/sum * 7 - 7; //the number of whole revolutions to do
                    //cout << "Currentdays = " << _currentDays << endl;
                    int ind = 0, currentSum = sum * _currentDays/7;
                    while(currentSum < days){
                        currentSum += arr[(ind++ + i) % 7];
                        //cout << "ind now " << ind << endl;
                    }
                    //cout << "days to go = " << _currentDays + ind << endl;
                    minAns = min(minAns, _currentDays + ind);
                }
            }
           printf("%d\n", minAns);
        }

    }
}
