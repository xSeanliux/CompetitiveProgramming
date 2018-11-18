#include <iostream>
using namespace std;

bool contains(int arr[], int check){
    int arrLen = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0 ; i < arrLen; i++){
        if(arr[i] == check) return true;
    }
    return false;
}

int generateNextNum(int Z, int L, int I, int M){
    return (Z*L + I) % M;
}

void go(int Z, int I, int M, int L, int c){

}

int main(){
    int Z, I, M, L;
    int c= 0;
    while(cin >> Z >> I >> M >> L){
        int ori = L;
        if(L + M + Z + I == 0) return 0; //if they're all 0, return
        int generateList[1000000]; //shiz and giggles big
        for(int i = 0; i < 1000000; i++){
            generateList[i] = -1;
        }
        int counter = 0;
        int newL;
        while(!contains(generateList, L)){
            newL = generateNextNum(Z, L, I, M);
            generateList[counter] = L;
            //cout << newL << endl;
            L = newL;
            counter++;
        }
        generateList[counter] = newL;
        //cout << "AY" << endl;
        //cout << generateList[1] << endl;
        //cout << generateList[counter] << endl;
        if(generateList[1] == generateList[counter]){
            counter -= 1;
        }
        printf("Case %d: %d\n", ++c, counter);

    }
}
