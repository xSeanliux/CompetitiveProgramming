#include <iostream>
#include <string.h>
#include <string.h>
#define MAXMIN 8*60
using namespace std;

int N, arr[600 + MAXMIN + 10], day = 0; //8 hours, 60 mins each, 10 for safety
string time1, time2, s;

int getMin(string s){
    return 60*((s[0]-'0')*10 + (s[1]-'0')) + 10*(s[3] - '0') + (s[4] - '0');
}

int main(){
    while(cin >> N){
        //cout << " N = " << N << endl;
        getline(cin, s);
        for(int i = 0; i < 601 + MAXMIN; i++)
            arr[i] = 0;
        for(int i = 0 ; i < N; i++){
            getline(cin, s);
            time1 = s.substr(0, 5);
            time2 = s.substr(6, 5);
            //cout << "MINS: " << getMin(time1) << " to " << getMin(time2) << endl;
            arr[getMin(time1)]++;
            arr[getMin(time2)]--;
        }
        int currentMax = 0, current = 0, currentSum = 0, currentStart = 599, maxStart = 0;
        maxStart = 599;
        //cout << maxStart << ": " <<currentMax << endl;
        for(int i = 600; i < 600 + MAXMIN; i++){
            //cout << "Current min: " << i << endl;
            currentSum += arr[i];
            //cout << "sum: " << currentSum << endl;
            if(!currentSum) {
                current++;
                if(current > currentMax){
                    //cout << "Start: " << currentStart << ", max: " << current << endl;
                    currentMax = current;
                    maxStart = currentStart;
                }
            } else {
                currentStart = i;
                current = 0;
            }
        }
        maxStart++;
        //cout << maxStart << endl;
        //cout << "|" << currentMax << endl;
        if(currentMax >= 60){
            printf("Day #%d: the longest nap starts at %d:%02d and will last for %d hours and %d minutes.\n", ++day, maxStart/60, maxStart % 60, currentMax/60, currentMax % 60);
        } else {
            printf("Day #%d: the longest nap starts at %d:%02d and will last for %d minutes.\n", ++day, maxStart/60, maxStart%60, currentMax);
        }
        //cout << maxStart << ": " <<currentMax << endl;
    }
}
