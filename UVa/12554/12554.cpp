#include <iostream>
#include <string.h>
using namespace std;

string lyr = "Happy birthday to you Happy birthday to you Happy birthday to Rujia Happy birthday to you";
string lyrics[20], names[100 + 5];
int head, n, times, nowguy;
void parseLyrics(){
    head = 0;
    string currentStr = "";
    int l = lyr.length();
    for(int i = 0 ; i< l; i++){
        if(lyr[i] == ' '){
            lyrics[head] = currentStr;
            //cout << lyrics[head] << " ";
            head++;
            currentStr = "";

        } else {
            currentStr += lyr[i];
            if(i == l-1){
                lyrics[head] = currentStr;
                //cout << lyrics[head] << " ";
                head++;
                currentStr = "";
            }
        }
    }
}

void print(){
    for(int i = 0 ; i < head; i++){
        cout << names[nowguy] << ": " << lyrics[i] << endl;
        nowguy++;
        nowguy %= n;
    }
}


int main(){
    parseLyrics();
    cin >> n;
    nowguy = 0;
    for(int i = 0; i < n; i++){
        cin >> names[i];
    }
    times = n/16 + 1;

    for(int i = 0 ; i < times; i++){
        print();
    }
}
