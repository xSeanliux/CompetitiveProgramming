#include <iostream>
using namespace std;

int arr[100][100], m, w, h;
bool canRemove[100][100];


int main(){
    while(cin >> h >> w){
        for(int i = 0 ; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> arr[i][j];
                canRemove[i][j] = !(arr[i][j] <= 1);
            }
        }
        for(int i = 0 ; i < h; i++){
            m = arr[i][0];
            for(int j = 0 ; j < w; j++){
                if(m < arr[i][j]) m = arr[i][j];
            }
            bool hasSwitched = false, flag = false;
            for(int j = 0 ; j < w; j++){
                if(m == arr[i][j] && !canRemove[i][j]) {
                    cout << "Found: arr[" << i << "][" << j << "]" << endl;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                for(int j = 0 ; j < w; j++){
                    if(m == arr[i][j]) {
                        if(canRemove[i][j]) canRemove[i][j] = hasSwitched;
                        hasSwitched = true;
                    }
                }
            }

        }
        cout << endl;
        for(int i = 0; i < h; i++){
            for(int j = 0 ; j < w; j++){
                //if(canRemove[i][j]) { arr[i][j] = 1;};
                cout << canRemove[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for(int i = 0 ; i < w; i++){
            m = arr[0][i];
            cout << "i = " << i << endl;
            for(int j = 0 ; j < h; j++){
                if(m < arr[j][i]) m = arr[j][i];
            }
            cout << m << endl;
            bool hasSwitched = false, flag = false;
            for(int j = 0 ; j < h; j++){
                if(m == arr[j][i] && !canRemove[j][i]) {
                    cout << "Found: arr[" << j << "][" << i << "]" << endl;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                for(int j = 0 ; j < h; j++){
                if(m == arr[j][i]) {
                    cout << "arr[" << j << "][" << i << "]" << endl;
                    if(canRemove[j][i])
                        canRemove[j][i] = hasSwitched;
                    hasSwitched = true;
                }
                }
            }

        }
        long long int sum = 0;
        cout << endl;
        for(int i = 0; i < h; i++){
            for(int j = 0 ; j < w; j++){
                if(canRemove[i][j]) {sum += arr[i][j] - 1; arr[i][j] = 1;};
                cout << canRemove[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for(int i = 0 ; i < h; i++){
            for(int j = 0; j < w; j++){
                cout <<  arr[i][j] << " ";
                //canRemove[i][j] = !(arr[i][j] <= 1);
            }
            cout << endl;
        }
        cout << sum << endl;
    }
}
