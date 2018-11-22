#include <iostream>
#include <stack>
using namespace std;

stack<int> A;
stack<int> station;
int target[1069];
int state[1000 + 1]; //0: A, 1: station, 2: B
int K;
bool isPossible, c = false;
int main()
{
    while(cin >> K)
    {
        //cout << "K is now " << K << endl;
        isPossible = true;
        if(c) cout << endl;
                else c = true;
        if(!K)
            return 0;

        while(cin >> target[0])
        {

            if(!target[0])
            {

                break;
            }
            isPossible = true;
            A = stack<int>();
            station = stack<int>();
            for(int i = K ; i > 0; i--)
            {
                A.push(i);
                //c
                //cout << "push " << i << endl;
            }
            //cout << "ye" << endl;
            for(int i = 1; i < K; i++)
            {
                state[i] = 0;
                cin>>target[i];
            }
            state[K] = 0;
            for(int i = 0 ; i < K && isPossible; i++)
            {
                int K = target[i];
                //cout << "target: " << K << endl;
                if(state[K] == 1)
                {
                    //cout << station.size() << endl;
                    //cout << "ayo" << endl;
                    if(station.top() != K)
                    {
                        isPossible = false;
                    }
                    station.pop();
                }
                else
                {
                    //cout << "hey" << endl;
                    while(!A.empty() && state[K] != 2)
                    {
                        int Z = A.top();
                        if(Z == K)
                        {
                            //cout << "no, " << Z << " goes straightto B" << endl;
                            state[Z] == 2;
                            A.pop();
                            break;
                        }
                        else
                        {
                            //cout << "no. " << Z << " goes to station " << endl;
                            A.pop();
                            station.push(Z);
                            state[Z] = 1;
                        }
                    }
                }

            }
            if(isPossible)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }

        }

    }
}
