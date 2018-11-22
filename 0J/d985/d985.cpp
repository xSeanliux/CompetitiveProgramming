#include <iostream>
using namespace std;

int qs(int arr[], int left, int right)
{
    int pivot = arr[left];
    int left_counter = left;

    if(right <= left) return 0 ;




    for(int i = left; i <= right; i++)
    {

        if(arr[i] <= pivot)
        {


            swap(arr[i], arr[left_counter]);
            left_counter++;



        }
    }
    swap(arr[left], arr[left_counter-1]);






    qs(arr, left, left_counter-2);
    qs(arr, left_counter, right);



}



int main(){
    int cases, len, minute, second;
    while(cin >> cases){
        for(int i = 0 ; i < cases; i++){
            cout << "Track " << i+1 << ": " << endl;
            cin >> len;
            int times[len];
            for(int i = 0; i < len; i++){
                cin >> minute >> second;
                times[i] = minute*60 + second;
            }
            qs(times, 0, len-1);
            cout << "Best Lap: " << times[0]/60 << " minute(s) " << times[0]%60 << " second(s)." << endl;
            int totalTime = 0;
            for(int i = 0; i < len; i++){
                totalTime += times[i];
            }
            cout << "Average: " << totalTime/60/len << " minute(s) " << (totalTime/len)%60 << " second(s)." << endl << endl;
        }
    }

}
