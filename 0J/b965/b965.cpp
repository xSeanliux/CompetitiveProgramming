#include <iostream>
using namespace std;
int M, N;
int arr[15][15]; //max 10*10
bool commands[14]; //max 10;
//flip and spin
void flip()  //x stays, y gets reversed.//if M is even, then the switch is at M/2; if M is odd, then the switch is at (M+1)/2
{
    for(int i = 0; i < (M-(M%2))/2; i++) //moves(Y)
    {
        for(int j = 0; j < N; j++) //doesnt move(X)
        {
            //cout << "Swapping " << arr[i][j] << " & " << arr[M-i-1][j] << endl;
            swap(arr[i][j], arr[M-i-1][j]);

        }
    }


}

void spin()  //the original spin
{
    int tmp_arr[N][M];//The original arr is M by N;


    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            //out << i<<", "<<j << " ==> " << N - j - 1<< ", " << i << endl;
            tmp_arr[N - j - 1][i] = arr[i][j];
            //swap(arr[i][j], arr[N - j - 1][i]);


        }
    }
    //cout << "Fom" << endl;
    swap(M, N);
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            arr[i][j] = tmp_arr[i][j];
        }
    }



}



int main()
{
    int C;
    while(cin >> M >> N >> C)
    {

        for(int i = 0 ; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cin >> arr[i][j];
            }
        }
        //cout << "C: " << C << endl;
        for(int i = 0; i < C; i++)
        {
            cin >> commands[i];
        }

        for(int i = C-1; i >= 0; i--)
        {
            if(commands[i])
            {
                //cout << "Command - 1 - Flip" << endl;
                flip();
            }
            else
            {
                //cout << "Command - 0 - Anti-Spin" << endl;
                spin(); //the inverse of the spin that the queston game
                //cout << endl;
            }
        }

        cout << M << " " << N << endl;
        for(int i = 0 ; i < M; i++)
        {
            cout << arr[i][0];
            for(int j = 1; j < N; j++)
            {
                cout << " "<< arr[i][j];
            }
            cout << endl;
        }


    }

}
