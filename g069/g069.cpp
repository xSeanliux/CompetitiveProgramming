#include <iostream>
#include <math.h>
using namespace std;

int cases, balls, toEat;


struct Ball{
    int num, weight;
};
Ball ballarr[1000 + 5];

bool cmp(Ball a, Ball b){
    for(int i = 0; i< balls ; i++){
            cout << ballarr[i].num << " ";
        }
    if(a.num < b.num){
        cout << "Swapping: " << a.num << " with " << b.num << endl;

        cout << endl;
        cout << toEat << " + " << a.weight << " + " << b.weight << " = " << (toEat + a.weight + b.weight) << endl;
        toEat += a.weight + b.weight;
    }
    return a.num <= b.num;

}



int main(){
    cin >> cases;
    for(int i = 0; i < cases; i++){
        cin >> balls;
        toEat = 0;
        for(int j = 0; j < balls; j++){
                cin >> ballarr[j].num;
        }
        for(int j = 0; j < balls; j++){
                cin >> ballarr[j].weight;
        }

        sort(ballarr, ballarr+balls, cmp);
        for(int i = 0; i< balls ; i++){
            cout << ballarr[i].num << " ";
        }
        cout << endl;
        cout << toEat << endl;
    }
}
