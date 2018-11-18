#include <iostream>
using namespace std;

int N;
int numList[20];


bool numList_contains(int j)
{
    //int arrlen = sizeof(arr) / sizeof(int);
    for(int i = 0 ; i < N; i++)
    {

        if(numList[i] == j) return true;

    }
    return false;
}


bool isPrime(int num)
{
    for(int i = 2; i*i <= num; i++)
    {
        if(num % i == 0) return false;
    }
    return true;
}





void DFS(int iteration)
{
    if(iteration >= N)
    {
        for(int i = 1; i <= N; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }




    for(int i = 2; i <= N ; i++)
    {
        if(isPrime(i + numList[iteration-1]))
        {
            cout << numList[iteration-1]  << " + " <<  i << " is prime" << endl;
            if(!numList_contains(i))
            {

                if(iteration == N)
                {
                    if(isPrime(i + numList[0]))
                    {
                        numList[iteration] = i;
                    }

                }
                else
                {
                    numList[iteration] = i;
                    DFS(iteration+1);
                }

            }
        }
    }









    /*
    cout <<"Running DFS(" << iteration << "). " << endl;
    if(iteration == N)
    {


        for(int i = 0 ; i < N; i++)
        {
            //cout << "i = " << i << endl;
            cout << numList[i] << ", " ;

        }

        return;
    }

    //check if the sum is prime. If so, find run the program with that. Else, break.
    cout << ".  " << endl;
    for(int i = 2; i <= N; i++)
    {
        //cout <<  find(numList, numList+N, i) << endl;
        //cout << "i = "<< i << endl;

        if(isPrime(i + numList[iteration-1]) && !numList_contains(i))
        {
            if(iteration == N)
            {
                if(isPrime(i + numList[0]))
                {

                    numList[iteration] = i;
                    cout << endl << endl << endl;
                    cout <<  numList[0]  << " + "<< i << "=" << i + numList[iteration-1]<< endl;
                }
                else
                {
                    return;
                }
            }
            else
            {
                numList[iteration] = i;


                DFS(iteration+1);
                cout << endl << endl << endl;
                cout <<  numList[iteration-1]  << " + "<< i << "=" << i + numList[iteration-1]<< endl;

            }


        }
        else
        {

            cout << i <<" does not match requirements. " << endl;
            //cout << "Either " << i << " + " << numList[iteration-1] << " is not prime" << endl;
            //cout << " or " << i << " is already taken." << endl;

        }


    }
    */

    //Fill one number, goto the next one.
    //which numbers? The ones that will be prime when summed with prev one.

}

int main()

{

    while(cin >> N)
    {
        for( int i = 0 ; i < N; i++)
        {
            numList[i] = 0;
        }
        numList[0] = 1;
        DFS(1);
        cout << endl;




    }


}
