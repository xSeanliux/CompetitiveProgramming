#include <iostream>
using namespace std;

int main()
{
    long a, translated;
    while(cin >> a)
    {

        while(a != 0){
            translated += a % 10;
            a /= 10;
            translated *= 10;
        }
        translated /=10;
        cout << translated;

    }
}


