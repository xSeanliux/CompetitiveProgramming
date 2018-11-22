#include <iostream>
using namespace std;
int comps;
int newSpace[10006], newSpacel = 0;
int y, a, b, d1;
int f(int comps, int numOfInputs, int y1, int a1, int b1, int currentSolutions[], int cSoll){
    //cout << numOfInputs << endl;
    newSpacel = 0;
    d1 = (b1-a1);
    if(numOfInputs == 1){ //first time entering, will put in.


            for(int i = y1 ; i < 10000; i+=d1){
            newSpace[newSpacel] = i;
            newSpacel++;
            }


    } else {
        for(int i = y1 ; i < 10000; i+=d1){
            for(int j = 0 ; j < cSoll; j++){
                if(i == currentSolutions[j]){
                    newSpace[newSpacel] = i;
                    newSpacel++;
                }
            }
        }
    }
    if(comps == numOfInputs){
        if(newSpacel > 0){
            //cout << "H" << endl;
            return newSpace[0];
        } else {
            return -1;

        }
    } else {

        //cout << "K" << endl;
        cin >> y >> a >> b;
        //cout << "J" << endl;
        return f(comps, numOfInputs+1, y, a, b, newSpace, newSpacel);
    }






}

int main(){
    int N = 0;
    int y1, a1, b1;
    while(cin >> comps){
        if(comps){
            N++;
            cout << "Case #" << N << ":" << endl;
        }  else {
            return 1;
        }


        cin >> y1 >> a1 >> b1;
        //cout << y1 << ", " << a1 << ", " << b1 << endl;
        if(comps == 1){
            cout << "The actual year is " << y1 << "."<< endl << endl;
            continue;
        }


        int currentSolutions[10005];
        int cSoll = 0;
        int ans = f(comps, 1, y1, a1, b1, currentSolutions, cSoll);

        if(ans > 0){
            cout << "The actual year is " << ans << "."<< endl << endl;
        } else {
            cout << "Unknown bugs detected." << endl << endl;
        }
    }
}
