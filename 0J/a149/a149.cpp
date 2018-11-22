#include <iostream>
using namespace std;
int main()
{
    int N, T, ans;
    while(cin >> N)
    {
        for(int i = 0 ; i < N ; i++)
        {
            cin >> T;
            if(T == 0){
                cout << 0 << endl;
                break;
            }
            ans = 1;
            while( T != 0)
            {
                ans *= T % 10;
                T /= 10;

            }
            cout << ans << endl;
        }

    }

}
