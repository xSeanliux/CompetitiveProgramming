#include <iostream>
using namespace std;

struct Kid{
    int a;
    int b;
};
Kid arr[200009];

int N;

bool has(int ind, int que){
    return (arr[ind].a == que || arr[ind].b == que);
}

int getNextKid(int ind){
    if(has(arr[ind].a, arr[ind].b)) return arr[ind].a;
    else return arr[ind].b;
}

int main(){
    cin >> N;
    if(N == 3){
        cout << "1 2 3" << endl;
        return 0;
    }
    for(int i = 1; i <= N; i++){
        cin >> arr[i].a >> arr[i].b;
    }
    cout << 1;
    int currentKid = 1;
    for(int i = 1; i < N; i++){
        currentKid = getNextKid(currentKid);
        cout << " " << currentKid;
    }
    cout << endl;
}
