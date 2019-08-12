#include <iostream>
#define endl '\n'
using namespace std;

int N;

int main(){
    cin >> N;
    if(N < 4){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if(N % 2){
        for(int i = N; i > 5; i -= 2){
            cout << i << " - " << i - 1 << " = 1" << endl;
        }
        for(int i = 0; i < (N - 5) / 2; i++){
            cout << "1 * 1 = 1" << endl;
        }
        cout << "5 * 4 = 20" << endl;
        cout << "3 + 2 = 5" << endl;
        cout << "5 - 1 = 4" << endl;
        cout << "20 + 4 = 24" << endl;
    } else {
        for(int i = N; i > 4; i -= 2){
            cout << i << " - " << i - 1 << " = 1" << endl;
        }
        for(int i = 0; i < (N - 4) / 2; i++){
            cout << "1 * 1 = 1" << endl;
        }
        cout << "1 * 2 = 2" << endl;
        cout << "2 * 3 = 6" << endl;
        cout << "6 * 4 = 24" << endl;
    }
}
