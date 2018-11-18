#include <iostream>
#include <string>
using namespace std;

int c, subs, ti;

bool isFound;
struct HW{
    string name;
    int t;
};

HW canDo[1000], haveToDo;

int main(){
    cin >> c;
    for(int ii = 0; ii < c; ii++){
        isFound = false;
        cin >> subs;

        for(int i = 0 ; i < subs; i++){
            cin >> canDo[i].name >> canDo[i].t;
        }
        cin >> ti >> haveToDo.name;
        printf("Case %d: ", ii+1);
        for(int i = 0 ; i < subs; i++){
            if(canDo[i].name == haveToDo.name){
                int K = canDo[i].t;
                if(K <= ti){
                    printf("Yesss\n");
                } else if(K <= ti + 5){
                    printf("Late\n");
                } else {
                    printf("Do your own homework!\n");
                }
                isFound = true;
            } else if(i == subs-1 && !isFound){ //fail
                printf("Do your own homework!\n");
            }
        }
    }
}
