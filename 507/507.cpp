#include <iostream>
using namespace std;

int c, l;

int main(){
    cin >> c;
    for(int sr = 1; sr <= c; sr++){
        cin >> l;
        int arr[l];
        for(int i = 0; i < l-1; i++){
            cin >> arr[i];
        }
        //cout << "done , l-2 = " << endl;
        int sum = 0, mSum = -1, s = 0, e, mS, mE = -1;
        for(int i = 0 ; i < l-1; i++){
            sum += arr[i];
            //cout << "i: " << i << ", sum : " << sum << endl;
            e = i;
            if(sum >= mSum){

                if(sum == mSum){
                    if(mE == -1 || mE - mS < e - s){
                        mE = e;
                        mS = s;
                    }
                } else {
                    mE = e;
                    mS = s;
                }
                mSum = sum;
            //cout <<" hey " << mS << ", " << mE << endl;
            }
            if(sum < 0){
                //cout <<" reached i = " << i << ", reset" << endl;
               sum = 0;
               s = i+1;
               //cout << " s: " << s << endl;
            }
            //cout << "s: " << s << ", e: " <<  e << endl;
        }
        //cout << mSum << endl;
        /*if(mS == 0){
            if(arr[0] >= 0){
                mS += 1;
            } else {
                mS += 2;
            }
        } else {
            mS += 2;
        }*/

        if(mSum >= 0)
            printf("The nicest part of route %d is between stops %d and %d\n", sr, mS+1, mE+2);
        else
            printf("Route %d has no nice parts\n", sr);
    }

}
