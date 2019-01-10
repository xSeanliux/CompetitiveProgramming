#include <iostream>
#include <string.h>
#include <map>
using namespace std;


map<char, char> m;

void initMap(){
    m.insert(pair<char, char>('W','Q'));
    m.insert(pair<char, char>('S','A'));
    m.insert(pair<char, char>('X','Z'));
    m.insert(pair<char, char>('W','Q'));
    m.insert(pair<char, char>('E','W'));
    m.insert(pair<char, char>('D','S'));
    m.insert(pair<char, char>('C','X'));
    m.insert(pair<char, char>('W','Q'));
    m.insert(pair<char, char>('R','E'));
    m.insert(pair<char, char>('F','D'));
    m.insert(pair<char, char>('V','C'));
    m.insert(pair<char, char>('T','R'));
    m.insert(pair<char, char>('G','F'));
    m.insert(pair<char, char>('B','V'));
    m.insert(pair<char, char>('Y','T'));
    m.insert(pair<char, char>('H','G'));
    m.insert(pair<char, char>('N','B'));
    m.insert(pair<char, char>('U','Y'));
    m.insert(pair<char, char>('J','H'));
    m.insert(pair<char, char>('M','N'));
    m.insert(pair<char, char>('I','U'));
    m.insert(pair<char, char>('K','J'));
    m.insert(pair<char, char>(',','M'));
    m.insert(pair<char, char>('O','I'));
    m.insert(pair<char, char>('L','K'));
    m.insert(pair<char, char>('.',','));
    m.insert(pair<char, char>('P','O'));
    m.insert(pair<char, char>(';','L'));
    m.insert(pair<char, char>('/','.'));
    m.insert(pair<char, char>('[','P'));
    m.insert(pair<char, char>(']','['));
    m.insert(pair<char, char>('\\',']'));
    m.insert(pair<char, char>('\'',';'));
    m.insert(pair<char, char>('1','`'));
    m.insert(pair<char, char>('2','1'));
    m.insert(pair<char, char>('3','2'));
    m.insert(pair<char, char>('4','3'));
    m.insert(pair<char, char>('5','4'));
    m.insert(pair<char, char>('6','5'));
    m.insert(pair<char, char>('7','6'));
    m.insert(pair<char, char>('8','7'));
    m.insert(pair<char, char>('9','8'));
    m.insert(pair<char, char>('0','9'));
    m.insert(pair<char, char>('-','0'));
    m.insert(pair<char, char>('=','-'));
    m.insert(pair<char, char>(' ',' '));
}

string s;

int main(){
    initMap();
    while(getline(cin, s)){
        //cout << "S = " << s << endl;
        int l = s.length();
        for(int i = 0; i < l; i++){
            cout << m[s[i]];
        }
        cout << endl;

    }
}
