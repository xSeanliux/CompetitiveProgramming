#include <iostream>
#include <string.h>
using namespace std;

string str, cS;

char getCode(string s){
    if(s == ".-"){
        return 'A';
    } else if(s == "-..."){
        return 'B';
    } else if(s == "-.-."){
        return 'C';
    } else if(s == "-.."){
        return 'D';
    } else if(s == "."){
        return 'E';
    } else if(s == "..-."){
        return 'F';
    } else if(s == "--."){
        return 'G';
    } else if(s == "...."){
        return 'H';
    } else if(s == ".."){
        return 'I';
    }  else if(s == ".---"){
        return 'J';
    } else if(s == "-.-"){
        return 'K';
    } else if(s == ".-.."){
        return 'L';
    } else if(s == "--"){
        return 'M';
    } else if(s == "-."){
        return 'N';
    } else if(s == "---"){
        return 'O';
    } else if(s == ".--."){
        return 'P';
    } else if(s == "--.-"){
        return 'Q';
    } else if(s == ".-."){
        return 'R';
    } else if(s == "..."){
        return 'S';
    } else if(s == "-"){
        return 'T';
    } else if(s == "..-"){
        return 'U';
    } else if(s == "...-"){
        return 'V';
    } else if(s == ".--"){
        return 'W';
    } else if(s == "-..-"){
        return 'X';
    } else if(s == "-.--"){
        return 'Y';
    } else if(s == "--.."){
        return 'Z';
    } else if(s == "-----"){
        return '0';
    } else if(s == ".----"){
        return '1';
    } else if(s == "..---"){
        return '2';
    } else if(s == "...--"){
        return '3';
    } else if(s == "....-"){
        return '4';
    } else if(s == "....."){
        return '5';
    } else if(s == "-...."){
        return '6';
    } else if(s == "--..."){
        return '7';
    } else if(s == "---.."){
        return '8';
    } else if(s == "----."){
        return '9';
    } else if(s == ".-.-.-"){
        return '.';
    } else if(s == "--..--"){
        return ',';
    } else if(s == "..--.."){
        return '?';
    } else if(s == ".----."){
        return '\'';
    } else if(s == "-.-.--"){
        return '!';
    } else if(s == "-..-."){
        return '/';
    } else if(s == "-.--."){
        return '(';
    } else if(s == "-.--.-"){
        return ')';
    } else if(s == ".-..."){
        return '&';
    } else if(s == "---..."){
        return ':';
    } else if(s == "-.-.-."){
        return ';';
    } else if(s == "-...-"){
        return '=';
    } else if(s == ".-.-."){
        return '+';
    }else if(s == "-....-"){
        return '-';
    } else if(s == "..--.-"){
        return '_';
    } else if(s == ".-..-."){
        return '"';
    } else if(s == ".--.-."){
        return '@';
    } else {
        return ' ';
    }
}

int c, head;
string _t;
string codes[2000];
int main(){
    cin >> c;
    getline(cin, _t);

    for(int it = 1; it <= c; it++){
        if(it > 1) cout << endl;
        getline(cin, str);
        int l = str.length();
        cS = "";
        head = 0;
        for(int i = 0; i < l; i++){
            if(str[i] == ' '){
                codes[head] = cS;
                head++;
                cS = "";
                if(str[i+1] == ' '){
                    //cout << "Space "<< endl;
                    cS += str[i];
                    codes[head] = cS;
                    head++;
                    cS = "";
                    i++;
                }
            } else {
                cS += str[i];
                if(i == l-1){
                    codes[head] = cS;
                    head++;
                    cS = "";
                }
            }
        }
        printf("Message #%d\n", it);
        for(int i = 0; i < head; i++){
            cout << getCode(codes[i]);
        }
        cout << endl;
    }
}
