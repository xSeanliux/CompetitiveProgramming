#include <iostream>
using namespace std;

int a, sum, average, ans;
int C[1000];
int c=  1;

int main()
{
    while(cin >> a){
        if(!a) return 0;
        ans = 0;
        sum = 0;
        average = 0;
        for(int i = 0; i < a; i++){
            cin >> C[i];
            sum += C[i];
        }
        average = sum/a;
        for(int i = 0; i < a; i++){
            if(C[i] > average){
                ans += C[i] - average;
            }
        }

        cout <<"Set #"<< c << endl;
        cout << "The minimum number of moves is " << ans << "." << endl<< endl;
        c++;
    }
}
