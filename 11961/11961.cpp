#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

bool visited[10 + 5];
int arr1[10];
char arr2[100];
int c, l, change, n;
string DNA;
string changes[10000000];
int head;

void dfs2(int N, int now){
    //cout << "Running dfs2(" << N << ", " << now << ")" << endl;
    if(now == N){
        //cout << "N : " << N << endl;
        string s = DNA;
        for(int i = 0 ; i < N; i++){
            s[arr1[i]] = arr2[i];
        }
        //cout << head << endl;
        changes[head] = s;
        head++;
        //cout << "New: " << s << endl;
        return;
    } else {
        for(int i = 0 ; i < 4; i++){
            char newC;
            if(i == 0){ //A
                newC = 'A';
            } else if(i == 1){ //C
                newC = 'C';
            } else if(i == 2){ //G
                newC = 'G';
            } else { //T
                newC = 'T';
            }
            if(newC == DNA[arr1[now]]) continue;
            arr2[now] = newC;
            //cout << arr2[now] << " hey" <<  endl;
            dfs2(N, now + 1);
        }
    }
}


void dfs1(int N, int now){
    //cout << "dfs(" << N << ", " << now << ")" << endl;
    if(now == N){
        for(int i = 0; i < N; i++){
            //visited[i] = false;
            cout << arr1[i] << " ";
        }
        cout << endl;
        //visited[arr1[now-1]] = false;
        //cout << "Ae" << endl;
        dfs2(N, 0);

        //cout << "A";
        return;
    } else {
        for(int i = 0 ; i < l; i++){
            //cout << "Hey" << endl;
            if(!visited[i]){
                //cout << "B " << now << " " <<  arr1[now] << "  " << i << endl;
                arr1[now] = i;
                //cout << "A" << endl;
                visited[i] = true;
                dfs1(N, now + 1);
                //cout << "A" << endl;
                //visited[i] = false;
            }
        }
    }
}

int main(){
    cin >> c;
    for(int k = 0 ; k < c; k++){
        head = 0;
        cin >> l >> change;
        cin >> DNA;

        for(int i = 0; i <= change; i++){
            cout << "Running dfs1: " << i << endl;
            for(int i = 0 ; i < l ;i++){
                visited[i] = false;
            }
            dfs1(i, 0);
        }
        sort(changes, changes + head);
        printf("%d\n", head);
        /*
        for(int i = 0 ; i < head; i++){

            cout << changes[i] << endl;
            if(changes[i] == "AAAAATTTTT") return 0;
        }
        */
        cout << "Done " << endl;
    }
}
