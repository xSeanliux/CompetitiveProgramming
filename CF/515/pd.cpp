#include <iostream>
using namespace std;

int n, mVol, boxes, objs[200005];



int main(){
    cin >> n >> boxes >> mVol;
    int maxItems = 0, nDiscard = 0, items;
    for(int i = 0 ; i < n; i++){
        cin >> objs[i];
    }
    int currentBox = 1, currentVol = 0;
    items = 0;
    for(int i = 0; i < n; i++){
        //cout << " i = " <<i << endl<< endl;
        items = 0;
        currentVol = 0;
        currentBox = 1;
        bool flag = true;
        if(i > n - maxItems) break;
        for(int j = i; j < n && currentBox <= boxes && flag; j++){
            if(mVol - currentVol >= objs[j]){
                //cout << "esy route" << endl;
                //cout << "Placing item " << j << " in box no." << currentBox << endl;
                currentVol += objs[j];
                items++;
            } else {
                if(currentBox < boxes){
                    currentBox++;
                    if(objs[j] > mVol){
                        if(maxItems < items) maxItems = items;
                        flag = false;
                        break;
                    }
                    items++;
                    //cout << "Placing item " << j << " in box no." << currentBox << endl;
                    currentVol = objs[j];
                } else if(currentBox == boxes){
                    if(maxItems < items) maxItems = items;
                    flag = false;
                    break;
                } else {
                    flag = false;
                    break;
                }
            }
            if(j == n-1 && maxItems < items) maxItems = items;
            //cout << "current box capacity : " << currentVol << endl;
        }
    }
    cout << maxItems << endl;
}
