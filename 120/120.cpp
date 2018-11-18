#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

string s;
int arr[101], head;
priority_queue<int> que;


void split(){
    head = 0;
    string cS = "";
    int l = s.length();
    for(int i = 0 ; i < l; i++){
        if(s[i] == ' ' || i == l-1){
            if(i == l-1){
                cS += s[i];
            }
            arr[head] = stoi(cS);
            que.push(stoi(cS));
            head++;
            //cout << "head = " << head << endl;
            cS = "";
        } else {
            cS += s[i];
        }
    }
}

void flip(int n){
    int newArr[101];
    for(int i = head - n ; i >= 0; i--){
        //cout << "head = " << head << ", n = " << n << ", i = " << i<< endl;
        newArr[head - n - i] = arr[i];
        //cout << "newarr[" << head - i - 1 << "] = arr[" << i << "]" << endl;
    }
    for(int i = head - n + 1; i < head; i++){
        newArr[i] = arr[i];
        //cout << "newarr[" << i << "] = arr[" << i << "]" << endl;
    }
    for(int i = 0; i < head; i++){
        arr[i] = newArr[i];
        //cout << "arr[" << i << "] = " << newArr[i] << endl;
    }
}

int main(){
    while(getline(cin, s)){
        cout << s << endl;
        split();
        int hasDone = 0;
        while(!que.empty()){
            int Z = que.top();
            //cout << "checking " << Z << endl;
            int ind;
            for(ind = 0; ind < head; ind++){
                if(arr[ind] == Z) break;
            }
            if(ind == 0 && hasDone < head - 1){
                flip(hasDone + 1);
                cout << hasDone + 1 << " ";
            } else if(ind != head - hasDone - 1){
                flip(head - ind);
                flip(hasDone + 1);
                cout << head - ind << " " << hasDone + 1 << " ";
            }
            hasDone++;
            que.pop();
        }
        cout << 0 << endl;
    }
}
