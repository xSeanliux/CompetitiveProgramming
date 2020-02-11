#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

string names[5] = {"Saki", "Megumin", "Rem", "Sagiri", "Kirino"};

int T, n = 5;

bool mp[5][5];
int rowsum[5], mrowsum;
int main(){
    ericxiao;
    cin >> T;
    while(T--){
        mrowsum = 0;
        for(int i = 0; i < n; i++){
            rowsum[i] = 0;
            for(int j = 0; j < n; j++){
                cin >> mp[i][j];
                rowsum[i] += mp[i][j];
            }
            mrowsum = max(rowsum[i], mrowsum);
        }
        int wins = 0;
        for(int i = 0; i < n; i++){
            if(rowsum[i] == mrowsum) wins++;
        }
        cout << wins << endl;

        for(int i = 0; i < n; i++){
            if(rowsum[i] == mrowsum) cout << names[i] << endl;
        }
    }
}
