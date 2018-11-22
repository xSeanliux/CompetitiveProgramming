#include <iostream>
#include <string>
using namespace std;

int s[130];
int head;
bool isCorrect = true;
void push(int a){
    s[head] = a;
    head++;
}


void pop(){
    head--;
    return;
}
int cases;
string query, t;
int main(){
    cin >> cases;
    getline(cin, t);
    for(int i = 0; i < cases; i++){
        getline(cin, query);
        if(query == ""){
            cout << "Yes" << endl;
        } else {
            head = 0;
            isCorrect = true;
            for(int i = 0; i < query.length(); i++){
                if(query[i] == '('){
                    push(1);
                } else if(query[i] == '['){
                    push(2);
                } else if(query[i] == ')'){
                    if(s[head-1] == 1){
                        pop();
                    } else{
                        isCorrect = false;
                    }
                } else if(query[i] == ']'){
                    if(s[head-1] == 2){
                        pop();
                    } else{
                        isCorrect = false;
                    }
                }
            }
            if(head != 0) isCorrect = false;
            if(isCorrect){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }

    }
}
