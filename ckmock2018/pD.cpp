#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


long long int N, arr[3], divs[1000000], head, minArea = 10000000000, minW = 10000000000;

long long int area(long long int a, long long int b, long long int c){
    return 2*(a*b + b*c + a*c);
}


int main(){
    cin >> N;
    head = 0;
    long long int k = ceil(sqrt(N));
    //cout << "k = " << k << endl;
    for(int i = 1 ; i <= k; i++){
        if(!(N % i)){
            divs[head] = i;
            head++;
            //cout << "head = " << head << endl;
        }
    }
    for(int i = 0 ; i < head; i++){
        for(int j = 0; j < head; j++){
            //cout << "divs[" << i << "] = " << divs[i] << ", divs[" << j << "] = " <<
            if(!(N % (divs[i] * divs[j]))){
                if(area(divs[i], divs[j], N/divs[i]/divs[j]) == minArea){
                    if(min(divs[i], min(divs[j], N/divs[i]/divs[j])) < minW){
                       //minArea = area(divs[i], divs[j], N/divs[i]/divs[j]);
                        minW = min(divs[i], min(divs[j], N/divs[i]/divs[j]));
                        arr[0] = divs[i];
                        arr[1] = divs[j];
                        arr[2] = N/divs[i]/divs[j];
                    }
                } else if(area(divs[i], divs[j], N/divs[i]/divs[j]) < minArea){
                        minArea = area(divs[i], divs[j], N/divs[i]/divs[j]);
                        minW = min(divs[i], min(divs[j], N/divs[i]/divs[j]));
                        arr[0] = divs[i];
                        arr[1] = divs[j];
                        arr[2] = N/divs[i]/divs[j];
                }
            }
        }
    }
    sort(arr, arr + 3);
    printf("%lld %lld %lld %lld\n", area(arr[0], arr[1], arr[2]), arr[0], arr[1], arr[2]);
    //cout << area(arr[0], arr[1], arr[2]) << " " << arr[0] << " " << arr[1] << " " << arr[2] << endl;
}
