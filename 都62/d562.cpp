#include <iostream>
using namespace std;

void run(int arr[], int len)  //delete first and then reverse
{
    for(int i = len; i >= 1; i--)
    {
        swap(arr[i], arr[len-i]);
    }


}

int main()
{
    int len;
    while(cin >> len)
    {
        int currentArr[len];
        for(int i = 0 ; i < len ; i++)
        {
            cin >> currentArr[i];
        }
        while(len >= 1)
        {
            for(int i = 0 ; i <= len; i++)
            {
                cout << currentArr[i] << ", ";
            }
            run(currentArr, len);
            len--;

            cout << endl;
        }

    }
}
