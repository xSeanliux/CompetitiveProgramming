#include <iostream>
#include <string.h>
using namespace std;
string stk[1000];
int currentIndex = 0;
int N;

int main()
{
    string currentCommand;
    string command;
    while(cin >> N)
    {
        for(int i = 0; i < N; i++)
        {
            cin >> currentCommand;
            if(currentCommand == "go")
            {
                getline(cin, command);
                command = command.substr(4, 10000000);
                stk[currentIndex] = command;
                cout << stk[currentIndex] << endl;
                currentIndex++;
            }
            else if(currentCommand == "use")
            {
                getline(cin, command);
                currentIndex--;


                if(currentIndex < 0)
                {

                    currentIndex =  0;
                }
                else
                {
                    cout << stk[currentIndex-1] << endl;

                }
            }
        }



    }
}
