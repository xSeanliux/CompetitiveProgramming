#include <iostream>
#include <math.h>
using namespace std;




int sortInt(int x, bool T)
{
    int len = floor(log10(abs(x))) + 1, ans;
    int arr[len]; // the length of the integer.
    for(int i = 0; i < len; i++)  // init the list
    {
        arr[i] = x % 10;
        x /= 10;
    }

    if(T)  //from big to small
    {
        for(int i = 0; i < len; i++)
        {
            for(int ii = i+1; ii < len; ii++)
            {
                if(arr[i] > arr[ii])
                {
                    int tmp = arr[i];
                    arr[i] = arr[ii];
                    arr[ii] = tmp;
                }
            }
        }



    }
    else if (!T)    //from small to big
    {

        for(int i = 0; i < len; i++)
        {
            for(int ii = i+1; ii < len; ii++)
            {
                if(arr[i] < arr[ii])
                {
                    int tmp = arr[i];
                    arr[i] = arr[ii];
                    arr[ii] = tmp;
                }
            }
        }


    }
    for(int i = 0; i < len; i++){
        ans += arr[i];
        ans *= 10;
    }
    return ans;



}



int f(int x)
{
    cout << sortInt(x, true) << " - " << sortInt(x, false) << " = " << sortInt(x, true) - sortInt(x, false);
    return sortInt(x, true) - sortInt(x, false);

}

int main()
{
    int counter, num, previnput = -1;
    while(cin >> num)
    {
        while(num != previnput)
        {

            previnput = num;
            num = f(num);
            counter++;
        }
        cout << counter << endl;
    }
}
