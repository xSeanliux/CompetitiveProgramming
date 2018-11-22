#include <iostream>
#include <string.h>
using namespace std;

int cases, comps, c1, c2, s ,f ;
int arr[100000000];
char com;
string command, cs;
int findAncestor(int index){
    if(arr[index] != index){
        arr[index] = findAncestor(arr[index]);
    }
    return index;
}

int main(){
    cin >> cases;
    for(int j = 0; j < cases; j++){
        s = f = 0;
        cin >> comps;
        getline(cin, command);
        while(getline(cin, command)){
            if(command == ""){
                printf("%d,%d", s, f);
                break;
            }
            com = command[0];
            cs = "";
            int i;
            for(i = 2; i < command.length(); i++){
                if(command[i] != ' '){
                    cs += command[i];
                    //cout << cs << endl;
                } else break;
            }
            c1 = stoi(cs);
            //cout << "c1 = " << c1 << endl;
            cs = "";
            i++;
            for(;i < command.length(); i++){
                if(command[i] != ' '){
                    cs += command[i];
                }
            }
            c2 = stoi(cs);
            //cout << "c2 = " << c2 << endl;
            if(com == 'c'){
                c1 = findAncestor(c1);
                c2 = findAncestor(c2);
                arr[c2] = c1;
                cout << "joining " << c2 << " with " << c1 << endl;
            } else{
                if(findAncestor(c1) == findAncestor(c2)){
                    cout << "c1's ancestor: " << findAncestor(c1) << ", c2s ancestor: " <<findAncestor(c2) << endl;
                    s++;
                } else {
                    cout << "c1's ancestor: " << findAncestor(c1) << ", c2s ancestor: " <<findAncestor(c2) << endl;
                    f++;
                }
            }
        }

    }
}
