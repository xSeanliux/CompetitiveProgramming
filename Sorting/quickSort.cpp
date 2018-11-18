#include <iostream>
#include <algorithm>
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



int main()
{

    int len;
    while(cin >> len)
    {
        int arr[len];
        for(int i = 0; i < len; i++)
        {
            cin >> arr[i];
        }


        cout << "before" << endl;

        for(int i = 0; i < len; i++)
        {
            cout << arr[i] << ", ";
        }


        qs(arr, 0, len);

        cout << "after" << endl;
        for(int i = 0; i < len; i++)
        {
            cout << arr[i] << ", ";
        }


    }





}
