#include <iostream>
using namespace std;

int c, friends, commands, comA, comB, arr[30000 + 10], nFriends[30000 + 10];

int findAncestor(int index){
    if(arr[index] != index){
        arr[index] = findAncestor(arr[index]);
    }
    return arr[index];
}


int main(){
    cin >> c;
    for(int aa = 0; aa < c; aa++){
        cin >> friends >> commands;
        for(int i = 0 ; i <= friends; i++){
            arr[i] = i;
            nFriends[i] = 1;
        }
        for(int k = 0; k < commands; k++){
            cin >> comA >> comB;
            comA = findAncestor(comA);
            comB = findAncestor(comB);
            if(comA != comB){
                arr[comA] = comB;
                nFriends[comB] += nFriends[comA];
            }
        }
        int maxf = 0;
        for(int l = 0; l <= friends; l++){
            if(nFriends[l] > maxf) maxf = nFriends[l];
        }
        cout << maxf << endl;
    }
}
