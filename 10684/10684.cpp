#include <iostream>
using namespace std;

int N, n, mS, cS;

int main(){
    while(cin >> N){
        if(!N) return 0;
        mS = cS = 0;
        for(int i = 0 ; i < N ; i++){
            cin >> n;
            cS += n;
            cS = max(cS, 0);
            if(mS < cS) mS = cS;
        }
        if(mS == 0){
            cout << "Losing streak." << endl;
        } else {
            cout << "The maximum winning streak is " << mS << "." << endl;
        }
    }
}
